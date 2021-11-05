#include <iostream>
#include "FileManager.h"


using namespace std;

int main() 
{
	FileManager* manager = new FileManager();

	const char* name{ "example.txt" };
	int iOpt = 0;
	std::cout << "What do you want doing? (write or read) 0 - 1" << std::endl;
	std::cin >> iOpt;
	
	manager->mOpenFile(name, iOpt);

	delete manager;
	return 0;
}