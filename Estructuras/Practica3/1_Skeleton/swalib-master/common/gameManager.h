#include "ball.h"
#include "timeCounter.h"

// typedef Ball tBalls[10];


class gameManager // SINGLETON
{
public:
	static gameManager* getInstance()
	{
		if (m_instance == nullptr)
			m_instance = new gameManager;
		return m_instance;
	}

private:
	gameManager() {}
	static gameManager* m_instance;
	// Max vel. of ball. (pixels/?).
	
public:
	const unsigned int NUM_BALLS = 10;	// Max. num balls.
	const float MAX_BALL_SPEED = 30.f;
	GLuint texsmallball = CORE_LoadPNG("data/tyrian_ball.png", false);
	GLuint texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);

	void init();
	// void mLogic(float);
	void LogicSlot(timeCounter*);
	void shutdownRender();
	void shutdown();
	void deleteBalls();
	
	Ball* balls = new Ball[10];
};
