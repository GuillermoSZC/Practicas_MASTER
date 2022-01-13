#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<vector>
#include<algorithm>
#include"Entity.h"

void DrawCharacter()
{

	printf("x");
}

int main()
{
	// int character = 20;
	int WIDTH = 80;
	int bulletCont = 0;
	bool exit = false, val = false;
	int contador = 0;

	Character* character = new Character(40);
	Bullet* bullet = new Bullet();
	Enemy* enemy = new Enemy();

	do
	{
		//Render
		printf("\r");
		for (int i = 0; i < WIDTH; i++)
		{
			if (i == character->GetPosition()) printf("x");
			else if (i == bullet->GetPosition() && !val) printf("<");
			else if (i == enemy->GetPosition() && !val) printf("*");
			else printf("_");
		}

		printf(" SCORE: %02d", contador);
		

		//Process Input
		if (_kbhit())
		{
			char key = _getch();
			switch (key)
			{
			case 'a': if (character->GetPosition() > 0) character->DecreaseMovement(); break;
			case 'd': if (character->GetPosition() < WIDTH - 1) character->IncreaseMovement(); break;
			case 'j': 
				if (bullet->GetPosition() < 0)
				{
					bullet->SetPosition(character->GetPosition());
				}
			break;				
			case 27: exit = true; break;
			}
		}

		if (bullet->GetPosition() >= 0) bullet->DecreaseMovement();

		// Enemy Movement
		enemy->IncreaseMovement();

		

		if (enemy->GetPosition() == character->GetPosition())
		{
			exit = true;
		}
		if (enemy->GetPosition() == bullet->GetPosition())
		{
			contador++;
			val = true;
		}

		Sleep(100);
	} while (!exit);

	system("cls");
	printf("                                                  GAME OVER\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	delete character;
	character = nullptr;
	delete bullet;
	bullet = nullptr;
	delete enemy;
	enemy = nullptr;
}