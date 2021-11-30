#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "vector2d.h"


struct Ball	// Info Ball
{
	vec2   pos;	// Position.
	vec2   vel;	// Velocity.
	GLuint gfx;	// OpenGL for id. for visualization purposes. 
	float  radius;	// Radius.

	Ball() :
		pos(0.0f),
		vel(0.0f),
		gfx(0),
		radius(0.0f)
	{}
};
// Array of balls.