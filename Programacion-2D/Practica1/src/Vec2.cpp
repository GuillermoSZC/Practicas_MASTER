#include "Vec2.h"
#include <math.h>

float* Vec2::suma(float a[2], float b[2])
{
	float suma[2];

	for (int i = 0; i < 2; ++i)
	{
		suma[i] = a[i] + b[i];
	}

	return suma;
}

float* Vec2::resta(float a[2], float b[2])
{
	float resta[2];

	for (int i = 0; i < 2; ++i)
	{
		resta[i] = a[i] - b[i];
	}

	return resta;
}

float* Vec2::producto(float a[2], float b[2])
{
	float producto[2];

	for (int i = 0; i < 2; ++i)
	{
		producto[i] = a[i] * b[i];
	}

	return producto;
}

float* Vec2::division(float a[2], float b[2])
{
	float division[2];

	for (int i = 0; i < 2; ++i)
	{
		division[i] = a[i] / b[i];
	}

	return division;
}

float vAbsoluto(float a[2])
{
	double vAbs;
	
	vAbs = sqrt(((double)a[0]* (double)a[0]) + ((double)a[1]* (double)a[1]));

	return (float)vAbs;
}