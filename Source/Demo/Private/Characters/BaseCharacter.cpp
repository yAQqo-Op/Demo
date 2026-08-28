// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"

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


