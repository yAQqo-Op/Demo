// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayTags/Dtags.h"

namespace DTags
{
	namespace DAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG(ActivateOnGinven, "DTags.DAbilities.ActivateOnGinven");
		UE_DEFINE_GAMEPLAY_TAG(Primary, "DTags.DAbilities.Primary");
		UE_DEFINE_GAMEPLAY_TAG(Death, "DTags.DAbilities.Death");
		UE_DEFINE_GAMEPLAY_TAG(Dodge, "DTags.DAbilities.Dodge");

		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG(BasicAttack, "DTags.DAbilities.Enemy.BasicAttack");
			UE_DEFINE_GAMEPLAY_TAG(Attack_a, "DTags.DAbilities.Enemy.Attack_a");
			UE_DEFINE_GAMEPLAY_TAG(Attack_bf, "DTags.DAbilities.Enemy.Attack_bf");
			UE_DEFINE_GAMEPLAY_TAG(Attack_bl, "DTags.DAbilities.Enemy.Attack_bl");
			UE_DEFINE_GAMEPLAY_TAG(Attack_c, "DTags.DAbilities.Enemy.Attack_c");
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
		UE_DEFINE_GAMEPLAY_TAG(Dodging, "DTags.Status.Dodging");
		UE_DEFINE_GAMEPLAY_TAG(Burn, "DTags.Status.Burn");

		namespace Combo
		{
			UE_DEFINE_GAMEPLAY_TAG(Attack1, "DTags.Status.Combo.Attack1");
			UE_DEFINE_GAMEPLAY_TAG(Attack2, "DTags.Status.Combo.Attack2");
			UE_DEFINE_GAMEPLAY_TAG(Attack3, "DTags.Status.Combo.Attack3");
			UE_DEFINE_GAMEPLAY_TAG(Attack4, "DTags.Status.Combo.Attack4");
		}
	}

	namespace AttackType
	{
		namespace Player
		{
			UE_DEFINE_GAMEPLAY_TAG(LightAttack, "DTags.AttackType.Player.LightAttack");
			UE_DEFINE_GAMEPLAY_TAG(HeavyAttack, "DTags.AttackType.Player.HeavyAttack");
		}

		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG(LightAttack, "DTags.AttackType.Enemy.LightAttack");
			UE_DEFINE_GAMEPLAY_TAG(HeavyAttack, "DTags.AttackType.Enemy.HeavyAttack");
		}
	}

	namespace Window
	{
		UE_DEFINE_GAMEPLAY_TAG(Combo, "DTags.Window.Combo");
	}
}
