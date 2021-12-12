#include "gameManager.h"
#include<iostream>


int Main(void)
{
	gameManager* oManager = new gameManager(); // Create obj gameManager()
	timeCounter* oTimer = new timeCounter();

	oTimer->StartCounter();
	oTimer->initPrevs();

	// Init game state.
	oManager->init();

	// Set up rendering.
	oManager->mSetUpRender();

	while (!SYS_GottaQuit()) {	// Controlling a request to terminate an application.
		oTimer->currentTime = oTimer->GetTime();
		oTimer->elapsedTime += oTimer->currentTime - oTimer->previousTime;
		oTimer->previousTime = oTimer->currentTime;
		// oTimer->initSlotsToProcess();

		while (oTimer->elapsedTime >= oTimer->fixedTick)
		{
			// Logic
			oManager->mLogic(oTimer->elapsedTime); // paso elapsed para el punto 2.7 de la practica
			oTimer->fixElapsed();
			// SYS_Sleep(17);
		}

		oTimer->calcFPS();

		// Render
		oManager->mRender(oTimer->currentTime, oTimer->frames, oTimer->logicTime);

		SYS_Pump();
	}

	// End app.
	oManager->shutdownRender();
	// Unload textures.
	oManager->shutdown();

	delete oManager; // Delete obj gameManager()
	oManager = nullptr;

	return 0;
}
