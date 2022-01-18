#include <vector>
#include "Ball.h"
#include "Bullet.h"
#include "Character.h"
#include "EntityComponent.h"

class WorldEngine // SINGLETON
{
public:
	static WorldEngine* getInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new WorldEngine;
		}
		return m_instance;
	}

private:
	const unsigned int NUM_BALLS;	// Max. num balls.
	const unsigned int NUM_BULLETS;	// Max. num bullets.
	const float MAX_BALL_SPEED;
	float dist;

	GLuint texsmallball;
	GLuint texbkg;
	GLuint background;
	GLuint texcharacter;
	GLuint texbullet;
	size_t idEntity;

	WorldEngine();
	static WorldEngine* m_instance;
	
public:
	std::vector<Entity*> entities; // creo el vector de Entidades
	// GETTERS & SETTERS
	GLuint GetTexbkg() { return texbkg; }
	GLuint GetTexSmallBall() { return texsmallball; }
	GLuint GetBkg() { return background; }
	size_t GetIDEntity() { return idEntity; }
	const unsigned int GetNumBalls() const { return NUM_BALLS; }
	float GetDist() { return dist; }

	// FUNCTIONS
	void ExpandDist();
	void LoadImages();
	void CreateEntities();
	void LogicSlot(TimeCounter& _Time);
	void ShutdownRender();
	void ShutdownEnt();	
};