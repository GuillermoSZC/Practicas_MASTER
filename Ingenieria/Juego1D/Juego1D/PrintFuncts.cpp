#include "PrintFuncts.h"

// AUX PRINT FUNCTIONS

void gotoCords(int x)
{
	COORD pos = { x + 17, 28 }; // 28 to set the height of the 'map' y 17 to center on x axis
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void clear()
{
	system("cls");
}