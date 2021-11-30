#include "gameManager.h"
#include<iostream>

__int64 counterStart = 0;
float frec = 0.f;

void StartCounter();
float GetTime();

int Main(void)
{
	gameManager* oManager = new gameManager(); // Create obj gameManager()
	StartCounter();
	float previousTime = GetTime();
	float currentTime = 0.f;
	float elapsed = 0.f;
	// float fixedTick = 60.f / 1.f;

	// Init game state.
	oManager->init();

	// Set up rendering.
	oManager->mSetUpRender();

	while (!SYS_GottaQuit()) {	// Controlling a request to terminate an application.

		currentTime = GetTime();
		elapsed = currentTime - previousTime;
		previousTime = currentTime;

		// Logic
		oManager->mLogic();

		// Render
		oManager->mRender(currentTime);

		SYS_Pump();	// Process Windows messages.

		// SYS_Sleep(17);	// To force 60 fps - Practica 2.0
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