#include "gameManager.h"
#include<iostream>

__int64 counterStart = 0;
float frec = 0.f;

void StartCounter();
float GetTime();
double clockToMilliseconds(clock_t);

int Main(void)
{
	gameManager* oManager = new gameManager(); // Create obj gameManager()

	StartCounter();

	float previousTime = GetTime();
	float currentTime = 0.f;
	float fixedTick = 1.f / 60.f;
	float elapsedTime = 0.f;
	clock_t deltaTime = 0;
	unsigned int frames = 0;
	float prevFps = GetTime();
	float currentFps = 0.f;

	// Init game state.
	oManager->init();

	// Set up rendering.
	oManager->mSetUpRender();

	while (!SYS_GottaQuit()) {	// Controlling a request to terminate an application.

		currentTime = GetTime();
		elapsedTime = currentTime - previousTime;
		previousTime = currentTime;

		while (elapsedTime >= fixedTick)
		{
			// Logic
			oManager->mLogic(fixedTick);
			elapsedTime -= fixedTick;
			currentFps++;
		}

		if (currentTime - prevFps >= 1.0f)
		{
			frames = currentFps;
			currentFps = 0.f;
			prevFps++;
		}
		
		// Render
		oManager->mRender(currentTime, frames);
	}

	// End app.
	oManager->shutdownRender();
	// Unload textures.
	oManager->shutdown();

	delete oManager; // Delete obj gameManager()

	return 0;
}

void StartCounter()
{
	LARGE_INTEGER li;

	// Performance counter
	if (QueryPerformanceFrequency(&li))
	{
		std::cout << "Frequency failed\n";
	}
	frec = float(li.QuadPart);

	QueryPerformanceCounter(&li);
	counterStart = li.QuadPart;
}

float GetTime()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return float(li.QuadPart - counterStart) / frec;
}