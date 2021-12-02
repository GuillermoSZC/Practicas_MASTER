#include "gameManager.h"
#include<iostream>
extern tBalls balls;

void gameManager::mLogic(float fixedVel)
{
	// Run balls
	for (unsigned int i = 0; i < NUM_BALLS; i++) 
	{
		// New Pos.
		// multiplico por fixedVel para cambiar la velocidad de las bolas y *20 para que vayan mas rapido 
		vec2 newpos = balls[i].pos + balls[i].vel * (fixedVel * 20); 

		// Collision detection.
		bool collision = false;
		int colliding_ball = -1;

		for (unsigned int j = 0; j < NUM_BALLS; j++) {
			if (i != j) {
				float limit2 = (balls[i].radius + balls[j].radius) * (balls[i].radius + balls[j].radius);
				if (vlen2(newpos - balls[j].pos) <= limit2) {
					collision = true;
					colliding_ball = j;
					break;
				}
			}
		}

		if (!collision) {
			balls[i].pos = newpos;
		}
		else {
			// Rebound!
			balls[i].vel = balls[i].vel * -1.f;
			balls[colliding_ball].vel = balls[colliding_ball].vel * -1.f;
		}

		// Rebound on margins.
		if ((balls[i].pos.x > SCR_WIDTH) || (balls[i].pos.x < 0)) {
			balls[i].vel.x *= -1.0;
		}
		if ((balls[i].pos.y > SCR_HEIGHT) || (balls[i].pos.y < 0)) {
			balls[i].vel.y *= -1.0;
		}
	}
}