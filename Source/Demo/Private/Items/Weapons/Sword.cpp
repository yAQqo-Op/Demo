// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Weapons/Sword.h"
#include "Components/StaticMeshComponent.h"

ASword::ASword()
{
    PrimaryActorTick.bCanEverTick = false;

    SwordMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwordMesh"));
    RootComponent = SwordMesh;
    SwordMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    SwordMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
}