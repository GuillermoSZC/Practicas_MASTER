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
		// std::cout << "Nombre del hombre lobo: " << cName << "\n";
		return cName;
	}

	virtual void vmGetStats() const override
	{
		std::cout << "\nHP: " << iHP << ", Attack : " << iAtk << ", Defense : " << iDef << "\n\n";
	}

	void mSetHp(unsigned int);
	void mSetAtk(unsigned int);
	void mSetDef(unsigned int);
	void mSetStats(unsigned int, unsigned int, unsigned int);
};