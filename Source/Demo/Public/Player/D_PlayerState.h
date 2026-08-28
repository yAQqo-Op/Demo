// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"

#include "D_PlayerState.generated.h"

class UAbilitySystemComponent;

UCLASS()
class DEMO_API AD_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	AD_PlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
private:

	UPROPERTY(VisibleAnywhere, Category = "Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
