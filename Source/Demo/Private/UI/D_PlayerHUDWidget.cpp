// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/D_PlayerHUDWidget.h"
#include "Characters/PlayerCharacter.h"
#include "Player/D_PlayerState.h"
#include "AbilitySystem/D_AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UD_PlayerHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Start hidden, wait for player binding
	SetVisibility(ESlateVisibility::Hidden);
}

void UD_PlayerHUDWidget::NativeDestruct()
{
	UnbindFromPlayer();
	Super::NativeDestruct();
}

const UD_AttributeSet* UD_PlayerHUDWidget::GetPlayerAttributeSet() const
{
	if (!CurrentPlayer) return nullptr;

	UAbilitySystemComponent* ASC = CurrentPlayer->GetAbilitySystemComponent();
	if (!ASC) return nullptr;

	return ASC->GetSet<UD_AttributeSet>();
}

void UD_PlayerHUDWidget::BindToPlayer(APlayerCharacter* Player)
{
	// 1. Clear any existing binding first
	UnbindFromPlayer();

	// 2. If player is invalid, hide UI
	if (!Player)
	{
		SetVisibility(ESlateVisibility::Hidden);
		return;
	}

	// 3. Store player reference
	CurrentPlayer = Player;

	// 4. Get GAS component
	UAbilitySystemComponent* ASC = Player->GetAbilitySystemComponent();
	if (!ASC)
	{
		SetVisibility(ESlateVisibility::Hidden);
		return;
	}

	// 5. Get attribute set
	CachedAttributeSet = ASC->GetSet<UD_AttributeSet>();
	if (!CachedAttributeSet)
	{
		SetVisibility(ESlateVisibility::Hidden);
		return;
	}

	// 6. Bind to attribute change delegates using Lambda to unpack FOnAttributeChangeData
	HealthDelegateHandle = ASC->GetGameplayAttributeValueChangeDelegate(
		UD_AttributeSet::GetHealthAttribute()
	).AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged(Data.NewValue, Data.OldValue);
		});

	ManaDelegateHandle = ASC->GetGameplayAttributeValueChangeDelegate(
		UD_AttributeSet::GetManaAttribute()
	).AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged(Data.NewValue, Data.OldValue);
		});

	// 7. Initialize all UI displays
	RefreshAllUI();

	// 8. Show UI
	SetVisibility(ESlateVisibility::Visible);

	UE_LOG(LogTemp, Log, TEXT("Player HUD bound to %s"), *Player->GetName());
}

void UD_PlayerHUDWidget::UnbindFromPlayer()
{
	if (!CurrentPlayer) return;

	UAbilitySystemComponent* ASC = CurrentPlayer->GetAbilitySystemComponent();
	if (ASC)
	{
		if (HealthDelegateHandle.IsValid())
		{
			ASC->GetGameplayAttributeValueChangeDelegate(UD_AttributeSet::GetHealthAttribute())
				.Remove(HealthDelegateHandle);
			HealthDelegateHandle.Reset();
		}
		if (ManaDelegateHandle.IsValid())
		{
			ASC->GetGameplayAttributeValueChangeDelegate(UD_AttributeSet::GetManaAttribute())
				.Remove(ManaDelegateHandle);
			ManaDelegateHandle.Reset();
		}
	}

	CurrentPlayer = nullptr;
	CachedAttributeSet = nullptr;
	SetVisibility(ESlateVisibility::Hidden);
}

// ========== Attribute Change Handlers (unpacked from FOnAttributeChangeData) ==========

void UD_PlayerHUDWidget::OnHealthChanged(float NewHealth, float OldHealth)
{
	if (CachedAttributeSet)
	{
		UpdateHealth(NewHealth, CachedAttributeSet->GetMaxHealth());
	}
}

void UD_PlayerHUDWidget::OnManaChanged(float NewMana, float OldMana)
{
	if (CachedAttributeSet)
	{
		UpdateMana(NewMana, CachedAttributeSet->GetMaxMana());
	}
}

// ========== UI Update Functions ==========

void UD_PlayerHUDWidget::UpdateHealth(float Current, float Max)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(Max > 0.0f ? Current / Max : 0.0f);
	}
	
}

void UD_PlayerHUDWidget::UpdateMana(float Current, float Max)
{
	if (ManaBar)
	{
		ManaBar->SetPercent(Max > 0.0f ? Current / Max : 0.0f);
	}
	
}

void UD_PlayerHUDWidget::RefreshAllUI()
{
	if (!CurrentPlayer || !CachedAttributeSet) return;

	UpdateHealth(CachedAttributeSet->GetHealth(), CachedAttributeSet->GetMaxHealth());
	UpdateMana(CachedAttributeSet->GetMana(), CachedAttributeSet->GetMaxMana());
}