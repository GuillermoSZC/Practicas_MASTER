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
