#include "ball.h"

typedef Ball tBalls[10];

class gameManager
{
private:
	const unsigned int NUM_BALLS = 10;	// Max. num balls.
	const float MAX_BALL_SPEED = 8.f;	// Max vel. of ball. (pixels/?).

	GLuint texsmallball = CORE_LoadPNG("data/tyrian_ball.png", false);
	GLuint texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);
public:

	void init();
	void mSetUpRender();
	void mRender(float);
	void mLogic();
	void shutdownRender();
	void shutdown();

	tBalls balls;
	gameManager() = default;
};
