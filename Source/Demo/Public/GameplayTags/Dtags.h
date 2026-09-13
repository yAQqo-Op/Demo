// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace DTags
{
	namespace DAbilities
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(ActivateOnGinven);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Primary);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Death);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Dodge);

		namespace Enemy
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(BasicAttack);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attack_a);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attack_bf);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attack_bl);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attack_c);
		}
	}

	namespace Events
	{
		namespace Player
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(BasicAttack);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(HitReact);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Death);
		}

		namespace Enemy
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(BasicAttack);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(HitReact);
		}
	}

	namespace Status
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Dead);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Dodging);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Burn);

		namespace Combo
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attack1);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attack2);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attack3);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attack4);
		}

	}

	namespace AttackType
	{
		namespace Player
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(LightAttack);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(HeavyAttack);
		}

		namespace Enemy
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(LightAttack);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(HeavyAttack);
		}
	}

	namespace Window
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Combo);
	}
}
