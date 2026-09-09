// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/D_GameplayAbility.h"
#include "PlayerDodge.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API UPlayerDodge : public UD_GameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Dodge")
	FString GetDodgeDirection() const;
};
