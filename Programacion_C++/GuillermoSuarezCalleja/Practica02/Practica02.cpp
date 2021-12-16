#include <iostream>
#include <vector>

// Prototipos de Funciones
void Parte1();
void Parte2();
void Parte3();
void Parte4();


int main() 
{
	Parte1();
	Parte2();
	Parte3();
	Parte4();

	return 0;
} // MAIN

void Parte1() 
{
	int iNum = 75469876;
	char* pChar = reinterpret_cast<char*>(&iNum);

	printf("%02hhX", * (pChar + 3));
	printf("%02hhX", *(pChar + 2));
	printf("%02hhX", *(pChar + 1));
	printf("%02hhX\n", *(pChar));
}

void Parte2()
{
	unsigned int iTabla[] = { 1,3,2,5,3, static_cast<unsigned int>(0xFFFFFFFF),2 };
	unsigned int* pTabla = reinterpret_cast<unsigned int*>(iTabla);
	unsigned int aux = 0;
	unsigned int iSize = sizeof(iTabla) / sizeof(iTabla[4]);

	for (unsigned int i = 0; i < iSize; ++i) 
	{
		// printf("%s", "ptr: ");
		// printf("%d\n", *(pTabla+i));
		if (aux < *(pTabla + i))
		{
			
			aux = *(pTabla + i);
			// printf("%s", "aux: ");
			// printf("%d\n", aux);
		}
	}
	printf("%d\n", sizeof(aux));
	std::cout << "Numero mayor: " << aux << std::endl;
}

void Parte3()
{
	unsigned int iTabla[] = { 1,3,2,5,3,0xFFFFFFFF,2 };
	unsigned char* pTabla = reinterpret_cast<unsigned char*>(iTabla);
	char aux = ' ';
	int tam = sizeof(iTabla) / sizeof(iTabla[4]);

	for (int i = 0; i < tam; ++i) 
	{ 
		if (aux < *(pTabla + i)) 
		{
			aux = *(pTabla + i);
		}
	}
	printf("%s", "Byte mayor: ");
	printf("%02hhX\n", aux);
}

void Parte4() 
{
	char cCadena[] = { 'H', 'o', 'l', 'a', '\0' };
	char* ptr = reinterpret_cast<char*>(&cCadena);
	int iTam = sizeof(cCadena);
	std::vector<char> vCadena(iTam);


	for (int x = 0, y = iTam-1; x < iTam - 1; ++x, --y)
	{
		vCadena[y] = *(ptr + x);
	}

	std::cout<<"Cadena invertida: ";
	for (int i = 0; i < iTam; ++i)
	{
		*(ptr + i) = vCadena[i];
		printf("%c", *(ptr + i));
	}
	printf("\n");
}