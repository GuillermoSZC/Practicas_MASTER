#pragma once
#include "Enemy.h"
#include<iostream>

class Werewolf : public Enemy
{
private:
	const char* cName;
	unsigned int iAtk, iDef, iHP;
	const char* cType;

public:
	Werewolf();
	Werewolf(const char* _cName);

	virtual ~Werewolf()
	{
		std::cout << "Objeto Hombre lobo " << cName << " borrado.\n";
	}

	virtual const char* vmGetType() const override
	{
		return cType;
	}

	virtual const char* vmGetName() const override
	{
		return cName;
	}

	virtual void vmGetStats() const override
	{
		std::cout << "\nHP: " << iHP << ", Attack : " << iAtk << ", Defense : " << iDef << "\n\n";
	}
};