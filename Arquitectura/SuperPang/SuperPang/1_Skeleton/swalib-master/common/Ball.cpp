#include "Ball.h"

Ball::Ball()
{
	SetName("ball");
	SetActive(true);

	AddComponent(new C_Renderable);
	AddComponent(new C_Transform);
	AddComponent(new C_Collision);
	AddComponent(new C_HealthComponent);
}
