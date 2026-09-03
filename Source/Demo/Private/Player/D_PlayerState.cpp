// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/D_PlayerState.h"
#include "AbilitySystem/D_AbilitySystemComponent.h"
#include "AbilitySystem/D_AttributeSet.h"

AD_PlayerState::AD_PlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UD_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UD_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AD_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
