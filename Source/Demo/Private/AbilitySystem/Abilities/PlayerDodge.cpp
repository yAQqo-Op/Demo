// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/PlayerDodge.h"
#include "Characters/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

FString UPlayerDodge::GetDodgeDirection() const
{
    // 1. 获取角色（用你的 APlayerCharacter）
    APlayerCharacter* Character = Cast<APlayerCharacter>(GetAvatarActorFromActorInfo());
    if (!IsValid(Character))
    {
        return TEXT("None");
    }

    // 2. 获取输入向量
    FVector InputVector = Character->GetCharacterMovement()->GetLastInputVector();
    if (InputVector.IsNearlyZero())
    {
        return TEXT("None");
    }

    // 3. 获取角色的前方向和右方向（用你的方式）
    FVector AvatarForward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
    FVector AvatarRight = GetAvatarActorFromActorInfo()->GetActorRightVector();

    // 4. 计算输入方向在角色局部坐标系中的分量
    float DotForward = FVector::DotProduct(InputVector, AvatarForward);
    float DotRight = FVector::DotProduct(InputVector, AvatarRight);

    // 5. 判断方向
    const float Threshold = 0.5f;

    if (DotForward > Threshold && FMath::Abs(DotRight) < Threshold)
    {
        return TEXT("Forward");
    }
    else if (DotForward < -Threshold && FMath::Abs(DotRight) < Threshold)
    {
        return TEXT("Back");
    }
    else if (DotRight > Threshold && FMath::Abs(DotForward) < Threshold)
    {
        return TEXT("Right");
    }
    else if (DotRight < -Threshold && FMath::Abs(DotForward) < Threshold)
    {
        return TEXT("Left");
    }

    // 对角线：取分量更大的方向
    if (FMath::Abs(DotForward) >= FMath::Abs(DotRight))
    {
        return (DotForward > 0) ? TEXT("Forward") : TEXT("Back");
    }
    else
    {
        return (DotRight > 0) ? TEXT("Right") : TEXT("Left");
    }
}