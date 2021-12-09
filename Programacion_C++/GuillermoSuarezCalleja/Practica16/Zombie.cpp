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
