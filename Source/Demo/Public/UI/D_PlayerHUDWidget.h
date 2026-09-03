// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "D_PlayerHUDWidget.generated.h"

class APlayerCharacter;
class UD_AttributeSet;
class UProgressBar;
class UTextBlock;

UCLASS()
class DEMO_API UD_PlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Bind to the player character (called by PlayerController)
	UFUNCTION(BlueprintCallable, Category = "UI")
	void BindToPlayer(APlayerCharacter* Player);

	// Unbind from current player and clean up listeners
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UnbindFromPlayer();

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	// ---------- UI Widget Bindings (names must match in Blueprint) ----------
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> HealthBar;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> ManaBar;

	// ---------- UI Update Functions ----------
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateHealth(float Current, float Max);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateMana(float Current, float Max);

	// Refresh all UI elements at once
	UFUNCTION(BlueprintCallable, Category = "UI")
	void RefreshAllUI();

	// Attribute change handlers (receives unpacked float values from Lambda)
	void OnHealthChanged(float NewHealth, float OldHealth);
	void OnManaChanged(float NewMana, float OldMana);

private:
	// Currently bound player
	UPROPERTY()
	TObjectPtr<APlayerCharacter> CurrentPlayer;

	// Cached attribute set
	UPROPERTY()
	const UD_AttributeSet* CachedAttributeSet;

	// Delegate handles for each attribute
	FDelegateHandle HealthDelegateHandle;
	FDelegateHandle ManaDelegateHandle;

	// Helper: get the attribute set from the current player
	const UD_AttributeSet* GetPlayerAttributeSet() const;
};
