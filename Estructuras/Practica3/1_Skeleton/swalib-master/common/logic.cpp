#include "gameManager.h"
#include<iostream>
extern tBalls balls;

void gameManager::mLogic(float elapsed)
{
	// Run balls
	for (unsigned int i = 0; i < NUM_BALLS; i++)
	{
		balls[i].Slot(elapsed, balls, NUM_BALLS, i);
	}
}