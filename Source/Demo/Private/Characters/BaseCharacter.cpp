// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffect.h"
#include "AbilitySystem/D_AttributeSet.h"

namespace Tags
{
	const FName Player = FName("Player");
	const FName Enemy = FName("Enemy");
}

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	//Tick and refresh bone
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void ABaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, bAlive);
}

void ABaseCharacter::GiveStartupAbilities()
{
	if (!IsValid(GetAbilitySystemComponent())) return;

	for (const auto& Ability : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability, 1);
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	}
}

void ABaseCharacter::InitializeAttributes() const
{
	checkf(IsValid(InitializeAttributesEffect), TEXT("InitializeAttributesEffect not set."));

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(InitializeAttributesEffect, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void ABaseCharacter::OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData)
{
	if (AttributeChangeData.NewValue <= 0.f)
	{
		HandleDeath();
	}
}

void ABaseCharacter::HandleDeath()
{
	bAlive = false;
	StopManaDrain();
}

void ABaseCharacter::HandleResPawn()
{
	bAlive = true;
}

void ABaseCharacter::ResetAttributes() 
{
	checkf(IsValid(ResetAttributesEffect), TEXT("ResetAttributesEffect not set."));

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(ResetAttributesEffect, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void ABaseCharacter::StartManaDrain()
{
	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	if (!IsValid(ASC)) return;

	if (!ManaDrainEffectClass) return;

	if (ManaDrainEffectHandle.IsValid())
	{
		ASC->RemoveActiveGameplayEffect(ManaDrainEffectHandle);
		ManaDrainEffectHandle.Invalidate();
	}

	ManaDrainEffectHandle = ASC->ApplyGameplayEffectToSelf(
		ManaDrainEffectClass->GetDefaultObject<UGameplayEffect>(),
		1.0f,
		ASC->MakeEffectContext()
	);

}

void ABaseCharacter::StopManaDrain()
{
	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	if (!IsValid(ASC)) return;

	if (ManaDrainEffectHandle.IsValid())
	{
		ASC->RemoveActiveGameplayEffect(ManaDrainEffectHandle);
		ManaDrainEffectHandle.Invalidate();
	}
}
