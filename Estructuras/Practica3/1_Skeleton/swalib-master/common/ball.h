#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "vector2d.h"
#include "timeCounter.h"

class Ball	// Info Ball
{
private:
	vec2   pos;	// Position.
	vec2   vel;	// Velocity.
	GLuint gfx;	// OpenGL for id. for visualization purposes. 
	float  radius;	// Radius.
public:
	// getters
	Ball();
	~Ball();
	vec2 getPos();
	vec2 getVel();
	float getRadius();
	GLuint getGfx();

	// setters
	void setPos(vec2);
	void setVel(vec2);
	void setRadius(float);
	void setGfx(GLuint);

	// Other funcions..
	void Slot(float, Ball[], const unsigned int, int);
	void LogicSlot(float, Ball[], const unsigned int, int, timeCounter*);
};