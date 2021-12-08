#include "Vampire.h"

Vampire::Vampire()
{
	cName = "common_vampire";
	iAtk = 15;
	iDef = 20;
	iHP = 300;
	cType = "Vampire";
	std::cout << "Objeto Vampiro creado por defecto.\n";
}

Vampire::Vampire(const char* _cName)
{
	cName = _cName;
	iAtk = 60;
	iDef = 80;
	iHP = 1200;
	cType = "Vampire boss";
	std::cout << "Objeto Vampiro creado, nombre: " << cName << "\n";
}

void Vampire::mSetHp(unsigned int _hp) 
{
	iHP = _hp;
}

void Vampire::mSetAtk(unsigned int _atk)
{
	iAtk = _atk;
}

void Vampire::mSetDef(unsigned int _def)
{
	iDef = _def;
}

void Vampire::mSetStats(unsigned int _hp, unsigned int _atk, unsigned int _def)
{
	iHP = _hp;
	iAtk = _atk;
	iDef = _def;
}