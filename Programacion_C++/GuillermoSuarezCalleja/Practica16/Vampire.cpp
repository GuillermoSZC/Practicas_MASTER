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
