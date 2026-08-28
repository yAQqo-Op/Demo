// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "D_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class DEMO_API AD_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TArray<UInputMappingContext*> InputMappingContexts;

	UPROPERTY(EditDefaultsOnly, Category = "Input|Movement")
	UInputAction* IA_Move;

	UPROPERTY(EditDefaultsOnly, Category = "Input|Movement")
	UInputAction* IA_Look;

	UPROPERTY(EditDefaultsOnly, Category = "Input|Movement")
	UInputAction* IA_Jump;

	UPROPERTY(EditDefaultsOnly, Category = "Input|Abilities")
	UInputAction* IA_Primary;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartJump();
	void StopJump();
	void Primary();
};
