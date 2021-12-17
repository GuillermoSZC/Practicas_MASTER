#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "vector2d.h"

class Render
{
public:
	static Render* getInstance()
	{
		if (instance == nullptr)
			Render* instance = new Render;
		return instance;
	}

private:
	Render() {}
	static Render* instance;
public:
	

	void mSetUpRender();
	void mRender(float, float, float);
	void DrawString(std::string, int, int);
	
};