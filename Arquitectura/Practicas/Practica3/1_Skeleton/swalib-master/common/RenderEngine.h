#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "vector2d.h"

class RenderEngine // SINGLETON
{
public:
	static RenderEngine* getInstance()
	{
		if (instance == nullptr)
		{
			RenderEngine* instance = new RenderEngine;
		}
		return instance;
	}

private:
	RenderEngine() {}
	static RenderEngine* instance;

public:
	void mSetUpRender();
	void mRender(float, float, float);
	void shutdownRender();
	void DrawString(std::string, int, int);
};