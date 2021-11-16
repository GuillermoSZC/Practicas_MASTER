#pragma once

class Vec2 {
public:
	float vec1[2];
	float vec2[2];

	Vec2() = default;
	Vec2(float fx[2], float fy[2])
	{
		for (int i = 0; i < 2; ++i)
		{
			vec1[i] = fx[i];
			vec2[i] = fy[i];
		}
	};

	float* suma(float[2], float[2]);
	float* resta(float[2], float[2]);
	float* producto(float[2], float[2]);
	float* division(float[2], float[2]);
	float* vAbsoluto(float[2]);

};