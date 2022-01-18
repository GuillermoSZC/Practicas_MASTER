#include "LogicManager.h"

// LOGIC MANAGER FUNCTIONS

LogicManager* LogicManager::m_instance = nullptr; // init singleton instance

#pragma region RENDER
void LogicManager::RenderMap()
{
	printf("\r");
	for (int i = 0; i < GetWidth(); i++)
	{
		gotoCords(i);
		SetConsoleTextAttribute(hConsole, 10); // set green color
		printf("_"); // print the '_' character i num times
	} // map render
}

void LogicManager::RenderEntities()
{
	gotoCords(character->GetPosition()); // places the character on the map in the established position
	SetConsoleTextAttribute(hConsole, 5); 
	printf("x");

	SetConsoleTextAttribute(hConsole, 14); 
	for (auto& bll : bulletL)
	{
		gotoCords(bll->GetPosition()); // print the BulletL running through the vector with the for each 
		printf("<");
	}

	for (auto& bll : bulletR)
	{
		gotoCords(bll->GetPosition()); 
		printf(">");
	}

	SetConsoleTextAttribute(hConsole, 12);
	for (auto& enm : enemyL)
	{
		gotoCords(enm->GetPosition()); // print the EnemyL running through the array with the for each 
		printf("*");
	}

	for (auto& enm : enemyR)
	{
		gotoCords(enm->GetPosition()); 
		printf("*");
	}
}

void LogicManager::RenderScore()
{
	gotoCords(GetWidth() + 1);
	SetConsoleTextAttribute(hConsole, 22);
	printf("SCORE %02d", GetScore()); // print the SCORE counter
	SetConsoleTextAttribute(hConsole, 23);
	gotoCords(GetWidth() + 10);
	printf(" L:%d", (bulletL.size() - 5) * -1); // print the number of left bullets that we have available
	gotoCords(GetWidth() + 14);
	printf(" R: %d", (bulletR.size() - 5) * -1); // print the number of right bullets that we have available
	SetConsoleTextAttribute(hConsole, 15); 
}

void LogicManager::Render()
{
	// calls to different render functions
	RenderMap();
	RenderEntities();
	RenderScore();
}
#pragma endregion

#pragma region LOGIC
void LogicManager::ProcessInput()
{
	if (_kbhit())
	{
		char key = _getch();
		switch (key)
		{
		case 'a': // updates movement to the player's left by pressing the 'a' key  
			if (character->GetPosition() > 0) character->DecreaseMovement(); 
			break; 
		case 'd': // updates movement to the player's right by pressing the 'd' key  
			if (character->GetPosition() < GetWidth() - 1) character->IncreaseMovement();
			break; 
		case 'j': // insert a BulletL in the vector by pressing 'j' 
			if (bulletL.size() < 5) 
			{
				LaserSound(); // plays the sound 'laser.wav' 
				bulletL.push_back(new Bullet(character->GetPosition())); // inserts a bullet into the BulletsL vector - MAX 5  
			}
			break;
		case 'k': // insert a BulletR in the vector by pressing 'k' 
			if (bulletR.size() < 5)
			{
				LaserSound();
				bulletR.push_back(new Bullet(character->GetPosition())); 
			}
			break;
		case 27: // pressing the 'esc' key we left the game 
			SetEnd(true);
			SetExit(true); 
			break; 
		}
	}
}

void LogicManager::SpawnEnemies()
{
	SetSpawn(rand() % 15); // I store a random number from 0 to 14 for spawn enemies to randomly 
	
	if (GetEnemySpawn() == 10) // if it is 10 spawning an enemyL 
	{
		enemyL.push_back(new Enemy(true, GetWidth())); 
	}
	else if (GetEnemySpawn() == 1) // if it is 1 spawning an enemyR
	{
		enemyR.push_back(new Enemy(false, GetWidth())); 
	}
}

void LogicManager::BulletMovement() // function to update the movement of the BulletL and BulletR 
{
	for (auto& bll : bulletL)
	{
		if (bll->GetPosition() >= 0) bll->DecreaseMovement();
		if (bll->GetPosition() <= 0) bulletL.erase(bulletL.begin()); //  if it collides with the left limit of the map it is removed 
	}

	for (auto& bll : bulletR)
	{
		if (bll->GetPosition() >= 0) bll->IncreaseMovement();
		if (bll->GetPosition() >= WIDTH) bulletR.erase(bulletR.begin()); //  if it collides with the right limit of the map it is removed 
	}
}

void LogicManager::EnBullCollision() // function to calculate collisions between enemies and bullets 
{
	for (auto& bll : bulletL) // I run through every bullet in the vector 
	{
		for (auto& enm : enemyL) // I run through each enemy of the vector for each bullet in the vector 
		{
			if (enm->GetPosition() > bll->GetPosition()) // when the enemy's position exceeds that of the bullet 
			{
				colliderL = bll->GetPosition() - enm->GetPosition(); // calculate the distance between enemy and bullet 
				if (colliderL <= 1)
				{
					IncreaseScore(); 
					bulletL.erase(bulletL.begin());// the bullet is removed from the vector 
					enemyL.erase(enemyL.begin());	 // the enemy is removed from the vector 
					if (GetScore() == 20)
					{
						SetExit(true);
					} // if you reach 20 SCORE points you win 
				}
			}
		}
	}

	for (auto& bll : bulletR) // just like the one above but with the BulletR 
	{
		for (auto& enm : enemyR)
		{
			if (bll->GetPosition() > enm->GetPosition())
			{
				colliderR = enm->GetPosition() - bll->GetPosition(); 
				if (colliderR <= 1)
				{
					IncreaseScore();
					bulletR.erase(bulletR.begin());
					enemyR.erase(enemyR.begin());
					if (GetScore() == 20)
					{
						SetExit(true);
					} 
				}
			}
		}
	}
}


void LogicManager::CharacterCollision() 
{
// Function that updates the movement of each bullet and checks if it collides with the character 
	for (auto& enm : enemyL) // collision with enemies coming from the left 
	{
		enm->IncreaseMovement();
		if (enm->GetPosition() >= character->GetPosition())
		{
			SetLose(true);
			SetExit(true); 
		} // comes out of the loop and you lose 
	} // collision between enemies spawneen on the right 

	for (auto& enm : enemyR) // collision with enemies coming from the right 
	{
		enm->IncreaseMovement();
		if (enm->GetPosition() <= character->GetPosition())
		{
			SetLose(true);
			SetExit(true); 
		} 
	} 
}

void LogicManager::Logic() // function that executes the game loop and makes the respective calls to render and logic 
{
	do
	{
		Render(); 
		ProcessInput();
		SpawnEnemies();
		BulletMovement();
		EnBullCollision();
		CharacterCollision();

		Sleep(60);
		clear();
	} while (!GetExit());

	GameOver();

	delete character;
	character = nullptr;
}
#pragma endregion

void LogicManager::GameOver() 
// method that is called when the game loop ends 
{
	if (GetLose() && !GetEnd()) // if lose
	{
		GameOverSound();
		gotoCords(35);
		SetConsoleTextAttribute(hConsole, 12); // GAME OVER letters in red 
		printf("GAME OVER\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		SetConsoleTextAttribute(hConsole, 15); // I leave the letters blank again by default after GAME OVER 
	}
	else if (!GetLose() && !GetEnd()) // if you win the game (you get to the indicated SCORE) 
	{
		YouWinSound();
		gotoCords(35);
		SetConsoleTextAttribute(hConsole, 2); 
		printf("YOU WIN\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		SetConsoleTextAttribute(hConsole, 15); 
	}
	else // if press 'esc'
	{
		gotoCords(35);
		SetConsoleTextAttribute(hConsole, 1); 
		printf("YOU END THE GAME\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		SetConsoleTextAttribute(hConsole, 15); 
	}
	system("pause");
}