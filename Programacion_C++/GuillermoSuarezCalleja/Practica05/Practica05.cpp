#include <iostream>
#include "FileManager.h"


using namespace std;

int main() 
{
	FILE* fichero(nullptr);
	FileManager* manager(new FileManager());

	const char* name{ "example.txt" };
	int iOpt(0);
	char* buffer(new char[100]);

	std::cout << "What do you want doing? (write or read) 0 - 1" << std::endl;
	std::cin >> iOpt;
	

	manager->mOpenFile(*&fichero, name, iOpt);
	std::cout<<"Numero de caracteres leidos: "<<manager->mReadFile(*&fichero, buffer)<<std::endl;

	delete buffer;
	delete manager;
	return 0;
}