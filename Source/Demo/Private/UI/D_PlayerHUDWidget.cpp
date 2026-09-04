// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/D_PlayerHUDWidget.h"
#include "Characters/PlayerCharacter.h"
#include "Player/D_PlayerState.h"
#include "AbilitySystem/D_AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Components/ProgressBar.h"

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

void UD_PlayerHUDWidget::BindToPlayer(APlayerCharacter* Player)
{
	UnbindFromPlayer();

	if (!Player || !IsValid(Player))
	{
		SetVisibility(ESlateVisibility::Hidden);
		return;
	}

	CurrentPlayer = Player;

	UAbilitySystemComponent* ASC = CurrentPlayer->GetAbilitySystemComponent();
	if (!ASC)
	{
		SetVisibility(ESlateVisibility::Hidden);
		return;
	}

	UD_AttributeSet* AttrSet = Cast<UD_AttributeSet>(CurrentPlayer->GetAttributeSet());
	if (!AttrSet)
	{
		SetVisibility(ESlateVisibility::Hidden);
		return;
	}

	HealthDelegateHandle = ASC->GetGameplayAttributeValueChangeDelegate(
		UD_AttributeSet::GetHealthAttribute()
	).AddUObject(this, &UD_PlayerHUDWidget::OnHealthChanged);

	ManaDelegateHandle = ASC->GetGameplayAttributeValueChangeDelegate(
		UD_AttributeSet::GetManaAttribute()
	).AddUObject(this, &UD_PlayerHUDWidget::OnManaChanged);

	RefreshAllUI();
	SetVisibility(ESlateVisibility::Visible);

	UE_LOG(LogTemp, Log, TEXT("Player HUD bound to %s"), *Player->GetName());
}

void UD_PlayerHUDWidget::UnbindFromPlayer()
{
	if (!CurrentPlayer)
	{
		SetVisibility(ESlateVisibility::Hidden);
		return;
	}

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
	SetVisibility(ESlateVisibility::Hidden);
}

void UD_PlayerHUDWidget::OnHealthChanged(const FOnAttributeChangeData& Data)
{
	if (CurrentPlayer)
	{
		UD_AttributeSet* AttrSet = Cast<UD_AttributeSet>(CurrentPlayer->GetAttributeSet());
		if (AttrSet)
		{
			UpdateHealth(Data.NewValue, AttrSet->GetMaxHealth());
		}
	}
}

void UD_PlayerHUDWidget::OnManaChanged(const FOnAttributeChangeData& Data)
{
	if (CurrentPlayer)
	{
		UD_AttributeSet* AttrSet = Cast<UD_AttributeSet>(CurrentPlayer->GetAttributeSet());
		if (AttrSet)
		{
			UpdateMana(Data.NewValue, AttrSet->GetMaxMana());
		}
	}
}

void UD_PlayerHUDWidget::UpdateHealth(float Current, float Max)
{
	if (HealthBar)
	{
		float Percent = (Max > 0.0f) ? (Current / Max) : 0.0f;
		HealthBar->SetPercent(FMath::Clamp(Percent, 0.0f, 1.0f));
	}
}

void UD_PlayerHUDWidget::UpdateMana(float Current, float Max)
{
	if (ManaBar)
	{
		float Percent = (Max > 0.0f) ? (Current / Max) : 0.0f;
		ManaBar->SetPercent(FMath::Clamp(Percent, 0.0f, 1.0f));
	}
}


void UD_PlayerHUDWidget::RefreshAllUI()
{
	if (!CurrentPlayer) return;

	UD_AttributeSet* AttrSet = Cast<UD_AttributeSet>(CurrentPlayer->GetAttributeSet());
	if (!AttrSet) return;

	UpdateHealth(AttrSet->GetHealth(), AttrSet->GetMaxHealth());
	UpdateMana(AttrSet->GetMana(), AttrSet->GetMaxMana());
}