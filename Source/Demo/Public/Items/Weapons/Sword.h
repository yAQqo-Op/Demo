// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sword.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class DEMO_API ASword : public AActor
{
    GENERATED_BODY()

public:
    ASword();

    // Attack collision control
    UFUNCTION(BlueprintCallable, Category = "Sword")
    void EnableAttackCollision();

    UFUNCTION(BlueprintCallable, Category = "Sword")
    void DisableAttackCollision();

protected:
    // Sword mesh as root component
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sword|Components")
    UStaticMeshComponent* SwordMesh;

    // Attack collision box
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sword|Components")
    UBoxComponent* AttackCollisionBox;



    // Called when attack collision overlaps
    UFUNCTION()
    void OnAttackCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult);
};