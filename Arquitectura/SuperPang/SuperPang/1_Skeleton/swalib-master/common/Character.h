#pragma once
#include "Components.h"

class Character : public Entity
{
private:
	int hp;

public:
	Character();
	~Character() {}
};
