// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayTags/Dtags.h"

namespace DTags
{
	namespace DAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG(ActivateOnGinven, "DTags.DAbilities.ActivateOnGinven");
		UE_DEFINE_GAMEPLAY_TAG(Death, "DTags.DAbilities.Death");

		UE_DEFINE_GAMEPLAY_TAG(Primary, "DTags.DAbilities.Primary");

		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG(BasicAttack, "DTags.DAbilities.Enemy.BasicAttack");
		}

	}
	

	namespace Events
	{
		namespace Player
		{
			UE_DEFINE_GAMEPLAY_TAG(BasicAttack, "DTags.Events.Player.BasicAttack");
			UE_DEFINE_GAMEPLAY_TAG(HitReact, "DTags.Events.Player.HitReact");
			UE_DEFINE_GAMEPLAY_TAG(Death, "DTags.Events.Player.Death");
		}

		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG(BasicAttack, "DTags.Events.Enemy.BasicAttack");
			UE_DEFINE_GAMEPLAY_TAG(HitReact, "DTags.Events.Enemy.HitReact");
		}
	}

	namespace Status
	{
		UE_DEFINE_GAMEPLAY_TAG(Dead, "DTags.Status.Dead");
	}

	namespace AttackType
	{
		namespace Player
		{

		}

		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG(LightAttack, "DTags.AttackType.Enemy.LightAttack");
			UE_DEFINE_GAMEPLAY_TAG(HeavyAttack, "DTags.AttackType.Enemy.HeavyAttack");
		}
	}
}
