// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/D_PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"


void AD_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!IsValid(InputSubsystem)) return;

	for (UInputMappingContext* Context : InputMappingContexts)
	{
		InputSubsystem->AddMappingContext(Context, 0);
	}

    UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
    if (!IsValid(EnhancedInputComponent)) return;

    EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ThisClass::Move);
    EnhancedInputComponent->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ThisClass::Look);
    EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Started, this, &ThisClass::StartJump);
    EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Completed, this, &ThisClass::StopJump);
	
    EnhancedInputComponent->BindAction(IA_Primary, ETriggerEvent::Started, this, &ThisClass::Primary);
}

void AD_PlayerController::Move(const FInputActionValue& Value)
{
    if (!IsValid(GetPawn())) return;

    const FVector2D MovementVector = Value.Get<FVector2D>();

    const FRotator YawRotation(0, GetControlRotation().Yaw, 0);
    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    GetPawn()->AddMovementInput(ForwardDirection, MovementVector.Y);
    GetPawn()->AddMovementInput(RightDirection, MovementVector.X);

}

void AD_PlayerController::Look(const FInputActionValue& Value)
{
    const FVector2D LookVector = Value.Get<FVector2D>();
    
    AddYawInput(LookVector.X);
    AddPitchInput(LookVector.Y);
}

void AD_PlayerController::StartJump()
{
	if (!IsValid(GetCharacter())) return;
	GetCharacter()->Jump();
}

void AD_PlayerController::StopJump()
{
	if (!IsValid(GetCharacter())) return;
	GetCharacter()->StopJumping();
}

void AD_PlayerController::Primary()
{

}
