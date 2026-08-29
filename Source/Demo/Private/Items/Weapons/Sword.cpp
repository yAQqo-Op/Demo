// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/Sword.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

ASword::ASword()
{
    PrimaryActorTick.bCanEverTick = false;

    // Sword mesh as root component
    SwordMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwordMesh"));
    RootComponent = SwordMesh;
    SwordMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    SwordMesh->SetCollisionResponseToAllChannels(ECR_Ignore);

    // Attack collision box attached to sword mesh
    AttackCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("AttackCollisionBox"));
    AttackCollisionBox->SetupAttachment(SwordMesh);
    AttackCollisionBox->SetBoxExtent(FVector(40.0f, 10.0f, 10.0f));
    AttackCollisionBox->SetRelativeLocation(FVector(30.0f, 0.0f, 0.0f));
    AttackCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    AttackCollisionBox->SetCollisionResponseToAllChannels(ECR_Ignore);

    // Bind overlap event
    AttackCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ASword::OnAttackCollisionBeginOverlap);
}

void ASword::EnableAttackCollision()
{
    AttackCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    AttackCollisionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void ASword::DisableAttackCollision()
{
    AttackCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    AttackCollisionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
}

void ASword::OnAttackCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (!OtherActor || OtherActor == GetOwner())
    {
        return;
    }

    // TODO: Apply damage using GAS
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red,
            FString::Printf(TEXT("Sword hit: %s"), *OtherActor->GetName()));
    }
}
