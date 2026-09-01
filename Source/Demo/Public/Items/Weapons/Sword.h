// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sword.generated.h"

class UStaticMeshComponent;

UCLASS()
class DEMO_API ASword : public AActor
{
    GENERATED_BODY()

public:
    ASword();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sword|Components")
    UStaticMeshComponent* SwordMesh;
};