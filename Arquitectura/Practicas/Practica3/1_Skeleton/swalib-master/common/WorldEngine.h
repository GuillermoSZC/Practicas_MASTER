#include "Ball.h"
#include "TimeCounter.h"

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
	WorldEngine() {}
	static WorldEngine* m_instance;
	
public:
	const unsigned int NUM_BALLS = 10;	// Max. num balls.
	const float MAX_BALL_SPEED = 15.f;
	GLuint texsmallball = CORE_LoadPNG("data/tyrian_ball.png", false);
	GLuint texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);

	void init();
	// void mLogic(float);
	void LogicSlot(TimeCounter*);
	void shutdown();
	
	Ball* balls = new Ball[10]; // creo el array de bolas
};
