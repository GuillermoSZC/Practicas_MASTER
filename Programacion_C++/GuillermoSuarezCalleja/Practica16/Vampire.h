#pragma once
#include "Enemy.h"
#include <iostream>

class Vampire : public Enemy
{
private:
	const char* cName;
	unsigned int iAtk, iDef, iHP;
	const char* cType;

public:
	Vampire(); 
	Vampire(const char* _cName);

	virtual ~Vampire()
	{
		std::cout << "Objeto Vampiro " << cName << " borrado.\n";
	}

	virtual const char* vmGetType() const override
	{
		return cType;
	}

	virtual const char* vmGetName() const override
	{
		// std::cout << "Nombre del vampiro: " << cName << "\n";
		return cName;
	}
	
	virtual void vmGetStats() const override
	{
		std::cout << "\nHP: " << iHP << ", Attack : " << iAtk << ", Defense : " << iDef << "\n\n";
	}
};