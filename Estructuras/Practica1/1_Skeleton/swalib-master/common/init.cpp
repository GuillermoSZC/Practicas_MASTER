#include "gameManager.h"

extern tBalls balls;

void gameManager::init()
{
	FONT_Init();	// Characters and symbols inicialization to draw on screen.
	for (unsigned int i = 0; i < NUM_BALLS; i++) {
		balls[i].pos = vec2(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT)); // Set a random position of ball[i]
		balls[i].vel = vec2(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED), CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED)); // Set a random speed of ball[i]
		balls[i].radius = 16.f; // Set a radius 16.f of ball[i]
		balls[i].gfx = texsmallball;
	}
}