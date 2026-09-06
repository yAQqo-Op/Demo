// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "D_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UD_PlayerHUDWidget;
struct FGameplayTag;
struct FInputActionValue;

UCLASS()
class DEMO_API AD_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

protected:

	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UD_PlayerHUDWidget> PlayerHUDWidgetClass;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TArray<UInputMappingContext*> InputMappingContexts;

	UPROPERTY(EditDefaultsOnly, Category = "Input|Movement")
	UInputAction* IA_Move;

	UPROPERTY(EditDefaultsOnly, Category = "Input|Movement")
	UInputAction* IA_Look;

	UPROPERTY(EditDefaultsOnly, Category = "Input|Abilities")
	UInputAction* IA_Primary;

	UPROPERTY()
	TObjectPtr<UD_PlayerHUDWidget> PlayerHUDWidget;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Primary();
	void ActivateAbility(const FGameplayTag& AbilityTag) const;
	void CreateAndBindHUD();
};
