// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/D_GameplayAbility.h"
#include "EnemyHitReact.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API UEnemyHitReact : public UD_GameplayAbility
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void CacheHitDirectionVectors(AActor* Instigator);

	UPROPERTY(BlueprintReadOnly, Category = "Abilities")
	FVector AvatarForward;

	UPROPERTY(BlueprintReadOnly, Category = "Abilities")
	FVector ToInstigator;
};
