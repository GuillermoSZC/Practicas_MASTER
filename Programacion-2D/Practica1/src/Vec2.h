#pragma once

class vec2 {
public:
	vec2();
	vec2(float x, float y);
	union
	{
		float v[2];
		struct
		{
			float x, y;
		};
	};

	vec2 suma(vec2&, vec2&);
	vec2 resta(vec2&, vec2&);
	vec2 producto(vec2&, vec2&);
	vec2 division(vec2&, vec2&);
	float vAbsoluto(vec2&);
	vec2 normal(vec2&);
	float pEscalar(vec2&, vec2&);

	float angle(const vec2& other) const;
	float distance(const vec2& other) const;
};