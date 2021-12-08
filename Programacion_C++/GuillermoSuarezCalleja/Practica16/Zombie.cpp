#include "Zombie.h"

Zombie::Zombie()
{
	cName = "common_zombie";
	iAtk = 10;
	iDef = 40;
	iHP = 700;
	cType = "Zombie";
	std::cout << "Objeto Zombie creado por defecto.\n";
}

Zombie::Zombie(const char* _cName)
{
	cName = _cName;
	iAtk = 40;
	iDef = 160;
	iHP = 2100;
	cType = "Zombie boss";
	std::cout << "Objeto Zombie creado, nombre: " << cName << "\n";
}

void Zombie::mSetHp(unsigned int _hp)
{
	iHP = _hp;
}

void Zombie::mSetAtk(unsigned int _atk)
{
	iAtk = _atk;
}

void Zombie::mSetDef(unsigned int _def)
{
	iDef = _def;
}

void Zombie::mSetStats(unsigned int _hp, unsigned int _atk, unsigned int _def)
{
	iHP = _hp;
	iAtk = _atk;
	iDef = _def;
}