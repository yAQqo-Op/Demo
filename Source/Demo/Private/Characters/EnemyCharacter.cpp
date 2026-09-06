// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyCharacter.h"
#include "AbilitySystem/D_AbilitySystemComponent.h"
#include "AbilitySystem/D_AttributeSet.h"
#include "AIController.h"

AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UD_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UD_AttributeSet>("AttributeSet");

}

UAbilitySystemComponent* AEnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AEnemyCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(GetAbilitySystemComponent())) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);

	if (!HasAuthority()) return;

	GiveStartupAbilities();
	InitializeAttributes();

	UD_AttributeSet* D_AttributeSet = Cast<UD_AttributeSet>(GetAttributeSet());
	if (!IsValid(D_AttributeSet)) return;

	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(D_AttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);

}

