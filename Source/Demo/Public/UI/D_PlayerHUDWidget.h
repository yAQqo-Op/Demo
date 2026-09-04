// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "D_PlayerHUDWidget.generated.h"

class APlayerCharacter;
class UD_AttributeSet;
class UAbilitySystemComponent;
class UProgressBar;
struct FOnAttributeChangeData;

UCLASS()
class DEMO_API UD_PlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Bind to the player character
	UFUNCTION(BlueprintCallable, Category = "UI")
	void BindToPlayer(APlayerCharacter* Player);

	// Unbind from current player and clean up listeners
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UnbindFromPlayer();

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> HealthBar;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> ManaBar;

	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateHealth(float Current, float Max);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateMana(float Current, float Max);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void RefreshAllUI();

	void OnHealthChanged(const FOnAttributeChangeData& Data);
	void OnManaChanged(const FOnAttributeChangeData& Data);

private:
	UPROPERTY()
	TObjectPtr<APlayerCharacter> CurrentPlayer;

	FDelegateHandle HealthDelegateHandle;
	FDelegateHandle ManaDelegateHandle;

};
