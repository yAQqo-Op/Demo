// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace DTags
{
	namespace DAbilities
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(ActivateOnGinven);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Death);

		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Primary);

		namespace Enemy
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(BasicAttack);
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
	}

	namespace AttackType
	{
		namespace Player
		{

		}

		namespace Enemy
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(LightAttack);
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(HeavyAttack);
		}
	}
}
