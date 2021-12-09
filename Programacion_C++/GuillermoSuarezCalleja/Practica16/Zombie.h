#pragma once
#include "Enemy.h"
#include <iostream>

class Zombie : public Enemy
{
private:
	const char* cName;
	unsigned int iAtk, iDef, iHP;
	const char* cType;

public:
	Zombie();
	Zombie(const char* _cName);

	virtual ~Zombie()
	{
		std::cout << "Objeto Zombie " << cName << " borrado.\n";
	}

	virtual const char* vmGetType() const override
	{
		return cType;
	}

	virtual const char* vmGetName() const override
	{
		// std::cout << "Nombre del Zombie: " << cName << "\n";
		return cName;
	}

	virtual void vmGetStats() const override
	{
		std::cout << "\nHP: " << iHP << ", Attack: " << iAtk << ", Defense: " << iDef << "\n\n";
	}
};