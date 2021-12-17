#include "ball.h"
#include <cstdio>



vec2 Ball::getPos()
{
	return pos;
}

float Ball::getRadius()
{
	return radius;
}

vec2 Ball::getVel()
{
	return vel;
}

GLuint Ball::getGfx()
{
	return gfx;
}

void Ball::setPos(vec2 _vPos)
{
	pos = _vPos;
}

void Ball::setVel(vec2 _vVel)
{
	vel = _vVel;
}

void Ball::setRadius(float _fRadius)
{
	radius = _fRadius;
}

void Ball::setGfx(GLuint _glGfx)
{
	gfx = _glGfx;
}

void Ball::Slot(float elapsed, Ball balls[], const unsigned int NUM_BALLS)
{
	for (unsigned int i = 0; i < NUM_BALLS; i++)
	{
		// New Pos.
		// multiplico por fixedVel para cambiar la velocidad de las bolas y *7 para que vayan mas rapido 
		vec2 newpos = balls[i].pos + balls[i].vel * (elapsed * 10);


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
			balls[i].vel *= -1.f;
			balls[colliding_ball].vel *= -1.f;
		}

		// Rebound on margins.
		if ((balls[i].pos.x >= SCR_WIDTH) || (balls[i].pos.x < 0)) {
			balls[i].vel.x *= -1.0;
		}
		if ((balls[i].pos.y >= SCR_HEIGHT) || (balls[i].pos.y < 0)) {
			balls[i].vel.y *= -1.0;
		}
	}
}