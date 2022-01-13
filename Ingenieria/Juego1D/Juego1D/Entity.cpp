#include "Entity.h"



#pragma region CHARACTER
void Character::SetPosition(int _Position)
{
	position = _Position;
}

void Character::IncreaseMovement()
{
	position++;
}

void Character::DecreaseMovement()
{
	position--;
}
#pragma endregion

#pragma region BULLET
void Bullet::IncreaseMovement()
{
	position++;
}

void Bullet::DecreaseMovement()
{
	position--;
}

void Bullet::SetPosition(int _Position)
{
	position = _Position;
}
#pragma endregion

#pragma region ENEMY
void Enemy::IncreaseMovement()
{
	position++;
}

void Enemy::DecreaseMovement()
{
	position--;
}

void Enemy::SetPosition(int _Position)
{
	position = _Position;
}
#pragma endregion