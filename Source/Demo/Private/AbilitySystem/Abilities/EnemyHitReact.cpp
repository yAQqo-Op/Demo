// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/EnemyHitReact.h"


void UEnemyHitReact::CacheHitDirectionVectors(AActor* Instigator)
{
	AvatarForward = GetAvatarActorFromActorInfo()->GetActorForwardVector();

	const FVector AvatarLocation = GetAvatarActorFromActorInfo()->GetActorLocation();
	const FVector InstigatorLocation = Instigator->GetActorLocation();

	ToInstigator = InstigatorLocation - AvatarLocation;
	ToInstigator.Normalize();
}
