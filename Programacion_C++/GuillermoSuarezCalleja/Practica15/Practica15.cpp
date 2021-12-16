#include <iostream>
#include "Com.h"
#include "File.h"
#include "Stream.h"
#include "Tcp.h"

int main()
{

// Prueba de crear y destruir objeto de la clase CStream individualmente.	
	CStream* objStream = new CStream();

	objStream->vmOpen("prueba.txt");
	objStream->vmRead("prueba.txt");
	objStream->vmWrite("prueba.txt");
	objStream->vmClose("prueba.txt");

	delete objStream;
	objStream = nullptr;

/*
	Se crea un array de punteros de la clase CStream que almacenan instancias de
	las clases hijas para así comprobar como el puntero de la clase Padre llama
	a los metodos virtuales sobreescritos por las clases Hijas
*/

	std::cout << "\n";

	CStream* obj[3];
	obj[0] = new CTcp;
	obj[1] = new CFile;
	obj[2] = new CCom;

	std::cout << "\n";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "\n";
		obj[i]->vmOpen("prueba.txt");
		obj[i]->vmRead("prueba.txt");
		obj[i]->vmWrite("prueba.txt");
		obj[i]->vmClose("prueba.txt");
		std::cout << "\nEXPLICIT CALL OF CSTREAM..\n"; 
		// Llamo unicamente a la clase CStream de manera explicita (necesario ->CStream::)
		obj[i]->CStream::vmOpen("prueba.txt");
		obj[i]->CStream::vmRead("prueba.txt");
		obj[i]->CStream::vmWrite("prueba.txt");
		obj[i]->CStream::vmClose("prueba.txt");
	}
	std::cout << "\n";

/*
	Se borran los objetos de la clase CStream y los de las respectivas
	clases Hijas
*/
	for (int i = 0; i < 3; ++i)
	{
		delete obj[i];
		obj[i] = nullptr;
	}
	return 0;
}