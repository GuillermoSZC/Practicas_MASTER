#include <iostream>

struct Nodo
{
	int dato;
	Nodo* siguiente;
};

void insertarLista(Nodo*&, int);


int main()
{
	Nodo* nodo = nullptr;

	int dato;

	std::cout << "Escribe num: " << std::endl;
	std::cin >> dato;
	insertarLista(nodo, dato);

	std::cout << "Escribe num: " << std::endl;
	std::cin >> dato;
	insertarLista(nodo, dato);

	std::cout << "Escribe num: " << std::endl;
	std::cin >> dato;
	insertarLista(nodo, dato);



	return 0;
}

void insertarLista(Nodo*& lista, int n)
{
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;

	Nodo* aux1 = lista;
	Nodo* aux2 = nullptr;

	while ((aux1 != nullptr) && (aux1->dato < n))
	{
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if (lista == aux1)
	{
		lista = nuevo_nodo;
	}
	else
	{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
	std::cout << "\nElemento " << n << " insertado a lista correctamente.\n";
}