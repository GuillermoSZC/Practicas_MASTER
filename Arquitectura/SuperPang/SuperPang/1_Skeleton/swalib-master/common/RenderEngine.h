#pragma once
#include<string>

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
	void SetUpRender();
	void RenderInit();
	void Render(float, float, float);
	void DrawString(std::string, int, int);
	void Shutdown();
};