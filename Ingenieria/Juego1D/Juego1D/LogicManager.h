#pragma once
#include<iostream>
#include<vector>
#include"Entity.h"
#include"PrintFuncts.h"
#include"SoundFuncts.h"

class LogicManager // SINGLETON LogicManager
{
public:
	static LogicManager* GetInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new LogicManager;
		}
		return m_instance;
	}

private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int WIDTH;
	bool exit, lose, end;
	int SCORE;
	int colliderL;
	int colliderR;
	int enemySpawn;
	
	Character* character = new Character(40);

	std::vector<Enemy*> enemyL;
	std::vector<Enemy*> enemyR;
	std::vector<Bullet*> bulletL;
	std::vector<Bullet*> bulletR;

	// CONSTRUCTOR
	LogicManager()
		: WIDTH(80), exit(false), lose(false), SCORE(0),
		colliderL(INT_MAX), colliderR(INT_MAX), enemySpawn(INT_MIN),
		end(false){}
	
	static LogicManager* m_instance; // INSTANCE

public:
	// GETTERS
	int GetWidth() { return WIDTH; }
	bool GetExit() { return exit; }
	bool GetLose() { return lose; }
	int GetScore() { return SCORE; }
	int GetEnemySpawn() { return enemySpawn; }
	bool GetEnd() { return end; }

	// SETTERS
	void SetExit(bool _Exit) { exit = _Exit; }
	void SetLose(bool _Lose) { lose = _Lose; }
	void SetSpawn(int _Spawn) { enemySpawn = _Spawn; }
	void SetEnd(bool _End) { end = _End; }
	//void SetWidth(int _Width) const { WIDTH = _Width; }

	// FUNCTIONS
	void IncreaseScore() { SCORE++; }

	// GAME FUNCTIONS
	void Render();
	void RenderMap();
	void RenderEntities();
	void RenderScore();
	void Logic();
	void ProcessInput();
	void SpawnEnemies();
	void BulletMovement();
	void EnBullCollision();
	void CharacterCollision();
	void GameOver();

}; // LogicManager