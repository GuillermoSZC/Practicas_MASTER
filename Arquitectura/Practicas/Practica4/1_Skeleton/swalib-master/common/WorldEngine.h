#include <vector>
#include "Ball.h"
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
	const unsigned int NUM_BALLS = 10;	// Max. num balls.
	const float MAX_BALL_SPEED = 15.f;

	GLuint texsmallball = 0;
	GLuint texbkg = 0;
	size_t idEntity = 0;

	WorldEngine() {}
	static WorldEngine* m_instance;
	
public:
	std::vector<Entity*> balls; // creo el vector de Entidades

	// GETTERS & SETTERS
	void SetTextures(GLuint _Texsmallball, GLuint _Texbkg);
	void SetId(size_t _IDEntity);

	GLuint GetTexbkg() { return texbkg; }
	GLuint GetTexSmallBall() { return texsmallball; }
	size_t GetIDEntity() { return idEntity; }

	// FUNCTIONS
	void LoadImages();
	void CreateEntities();
	void LogicSlot(TimeCounter& _Time);
	void ShutdownRender();
	void ShutdownEnt();	
};
