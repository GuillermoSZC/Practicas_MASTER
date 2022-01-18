#include "Entity.h"

// ENTITY FUNCTIONS

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
Enemy::Enemy(bool _Spawn, int _End) 
	: spawn(_Spawn),
	position(0)
{
	if (spawn)
	{
		position = 0;
	}
	else if (!spawn)
	{
		position = _End;
	}
}

void Enemy::IncreaseMovement()
{
	if (spawn) 
	{
		position++;
	} 
	else if (!spawn)
	{
		position--;
	}
}

void Enemy::SetPosition(int _Position)
{
	position = _Position;
}
#pragma endregion