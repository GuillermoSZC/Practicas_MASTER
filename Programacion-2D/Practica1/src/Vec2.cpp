#include "vec2.h"
#include <math.h>

vec2::vec2() {}

vec2::vec2(float x, float y)
{
	v[0] = x;
	v[1] = y;
}

vec2 vec2::suma(vec2& a, vec2& b)
{
	vec2 sum;
	sum.v[0] = a.v[0] + b.v[0];
	sum.v[1] = a.v[1] + b.v[1];

	return sum;
}
vec2 vec2::resta(vec2& a, vec2& b)
{
	vec2 rest;
	rest.v[0] = a.v[0] - b.v[0];
	rest.v[1] = a.v[1] - b.v[1];

	return rest;
}

vec2 vec2::producto(vec2& a, vec2& b)
{
	vec2 prod;
	prod.v[0] = a.v[0] * b.v[0];
	prod.v[1] = a.v[1] * b.v[1];

	return prod;
}

vec2 vec2::division(vec2& a, vec2& b)
{
	vec2 div;
	div.v[0] = a.v[0] / b.v[0];
	div.v[1] = a.v[1] / b.v[1];

	return div;
}

float vec2::vAbsoluto(vec2& a)
{
	float vAbs;
	float prod = (float)pow(a.v[0], 2) + (float)pow(a.v[1], 2);
	vAbs = (float)sqrt(prod);

	return vAbs;
}

vec2 vec2::normal(vec2& a)
{
	float nm = vAbsoluto(a);
	if (nm == 0)
	{
		return vec2(0, 0);
	}

	return vec2((a.x / nm), a.y /nm);
}

float vec2::pEscalar(vec2& a, vec2& b)
{
	float escalar = a.v[0] * b.v[0] + a.v[1] * b.v[1];

	return escalar;
}

float vec2::angle(const vec2& other) const 
{
	float x = 0.f;

	return x;
}

float vec2::distance(const vec2& other) const
{
	float x = 0.f;

	return x;
}