#include "Character.h"

Character::Character() : hp(0)
{
	SetName("character");
	SetActive(true);

	AddComponent(new C_Renderable);
	AddComponent(new C_Transform);
	AddComponent(new C_Collision);
	AddComponent(new C_CharactActions);
	AddComponent(new C_HealthComponent);

	FindComponent<C_CharactActions>()->SetPos(vec2(SCR_WIDTH / 2, 32));
	FindComponent<C_CharactActions>()->SetVel(vec2(200, 0));
	FindComponent<C_Collision>()->SetRadius(32.f);
}