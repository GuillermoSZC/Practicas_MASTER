#include <iostream>
#include "TList.h"
#include "Zombie.h"
#include "Werewolf.h"
#include "Vampire.h"

int main()
{
	TList* lista = new TList();

	Zombie* zombieBoss = new Zombie("Nemesis");
	Zombie* commZombie = new Zombie();
	Werewolf* werewBoss = new Werewolf("Garou");
	Werewolf* commWerewolf = new Werewolf();
	Vampire* vampireBoss = new Vampire("Dracula");
	Vampire* commVampire = new Vampire();

	// inserto los objetos en la lista
	lista->mPush(zombieBoss);
	lista->mPush(commZombie);
	lista->mPush(werewBoss);
	lista->mPush(commWerewolf);
	lista->mPush(vampireBoss);
	lista->mPush(commVampire);

	// compruebo si cada funcion de la lista funciona correctamente con los distintos objetos
	lista->mShowList();

	std::cout << "\nSize of list: \n" << lista->mSize() << std::endl;

	std::cout << "\n..First element of list..\n" << lista->mFirst()->vmGetName();

	std::cout << "\n..Next element of list..\n" << lista->mNext()->vmGetName();

	std::cout << "\n..First element of list erased..\n" << lista->mPop()->vmGetName();

	std::cout << "\n..First element of list..\n" << lista->mFirst()->vmGetName();

	std::cout << "\nSize of list: \n" << lista->mSize() << std::endl;

	std::cout << "\n..Reset list..\n";
	lista->mReset();

	std::cout << "\n";
	// borro la lista
	delete lista;
	lista = nullptr;

	// borro todos los objetos creados
	delete zombieBoss;
	zombieBoss = nullptr;
	delete werewBoss;
	werewBoss = nullptr;
	delete vampireBoss;
	vampireBoss = nullptr;
	delete commZombie;
	commZombie = nullptr;
	delete commWerewolf;
	commWerewolf = nullptr;
	delete commVampire;
	commVampire = nullptr;

	return 0;
}