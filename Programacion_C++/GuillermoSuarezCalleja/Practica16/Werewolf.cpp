#include "Werewolf.h"

Werewolf::Werewolf()
{
	cName = "common_werewolf";
	iAtk = 40;
	iDef = 10;
	iHP = 400;
	cType = "Werewolf";
	std::cout << "Objeto Hombre lobo creado por defecto.\n";
}

Werewolf::Werewolf(const char* _cName)
{
	cName = _cName;
	iAtk = 160;
	iDef = 40;
	iHP = 1600;
	cType = "Werewolf boss";
	std::cout << "Objeto Hombre lobo creado, nombre: " << cName << "\n";
}

void Werewolf::mSetHp(unsigned int _hp)
{
	iHP = _hp;
}

void Werewolf::mSetAtk(unsigned int _atk)
{
	iAtk = _atk;
}

void Werewolf::mSetDef(unsigned int _def)
{
	iDef = _def;
}

void Werewolf::mSetStats(unsigned int _hp, unsigned int _atk, unsigned int _def)
{
	iHP = _hp;
	iAtk = _atk;
	iDef = _def;
}