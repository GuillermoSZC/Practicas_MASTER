#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool exit = false, shootL = false, shootR = false;

	unsigned int contador = 0;
	unsigned int WIDTH = 100;
	unsigned int char_x = 50;

	std::vector<unsigned int> bullet_left;
	std::vector<unsigned int> bullet_right;

	unsigned int enemy_left = 0;
	unsigned int enemy_right = WIDTH;

	unsigned int contBalasL = 0;
	unsigned int contBalasR = 0;

	do
	{
		// Render
		printf("\r");
		for (unsigned int i = 0; i < WIDTH; ++i)
		{
			if (i == char_x)
			{
				SetConsoleTextAttribute(hConsole, 10);
				printf("x");
			}
			else if (shootL)
			{
				SetConsoleTextAttribute(hConsole, 14);
				printf("<");
			}
			else if (shootR)
			{
				SetConsoleTextAttribute(hConsole, 14);
				printf(">");
			}
			else if (i == enemy_left)
			{
				SetConsoleTextAttribute(hConsole, 12);
				printf("*");
			}
			else if (i == enemy_right)
			{
				SetConsoleTextAttribute(hConsole, 12);
				printf("*");
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 1);
				printf("_");
			}
		}
		SetConsoleTextAttribute(hConsole, 14);
		printf(" SCORE: %02d", contador);
		// Process Input
		if (_kbhit())
		{
			char ch = _getch();
			switch(ch)
			{
			case 'a': if (char_x > 0) char_x--; break;
			case 'd': if (char_x < WIDTH - 1) char_x++; break;
			case 'j': 
				if (contBalasL < 5)
				{
					shootL = true;
					bullet_left.push_back(char_x - 1);
					contBalasL++;
				}
				break;
			case 'k': 
				if (contBalasR < 5)
				{
					shootR = true;
					bullet_right.push_back(char_x + 1);
					contBalasR++;
				} 
				break;
			case 27: if (char_x > 0) exit = true; break;
			}
		}

		// Move Bullets
		if (bullet_left.size() > 0)
		{
			if (bullet_left[contBalasL] >= 0)
			{
				bullet_left[contBalasL]--;
			}
		}

		if (bullet_right.size() > 0)
		{
			if (bullet_right[contBalasR] >= 0) 
			{
				bullet_right[contBalasR]++;
			}
		}

		// Move Enemies
		if (enemy_left >= 0) enemy_left++;
		if (enemy_right >= 0) enemy_right--;

		// Kill Enemies and destroy bullets 
		// @TODO:
		if (bullet_left.size() > 0 && bullet_left[contBalasL] == enemy_left)
		{
			bullet_left.pop_back();
			contador++;
		}
		if (bullet_right.size() > 0 && bullet_right[contBalasR] == enemy_right)
		{
			bullet_right.pop_back();
			contador++;
		}

		// Dead
		if (enemy_left >= char_x || enemy_right <= char_x)
		{
			exit = true;
		}

		shootL = false;
		shootR = false;

		Sleep(100);
	} while (!exit);

	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	printf("                                                    YOU LOSE\n\n\n\n\n\n\n\n");
	
	return 0;
}