#include "Bullet.h"

Bullet::Bullet()
{
	SetName("bullet");
	SetActive(false);

	AddComponent(new C_Renderable);
	AddComponent(new C_Transform);
	AddComponent(new C_Collision);
	AddComponent(new C_ShotBullet);
	AddComponent(new C_HealthComponent);
}