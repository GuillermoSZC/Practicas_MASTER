#include "Ball.h"

Ball::Ball()
{
	AddComponent(new C_Transform);
	AddComponent(new C_Collision);
	AddComponent(new C_Renderable);
}
