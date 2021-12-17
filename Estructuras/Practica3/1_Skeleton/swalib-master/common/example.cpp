#include "gameManager.h"
#include<iostream>
#include"Render.h"



int Main(void)
{
	gameManager* oManager = gameManager::getInstance();
	timeCounter* oTimer = new timeCounter();
	Render* oRender = Render::getInstance();

	oTimer->StartCounter();
	oTimer->initPrevs();

	// Init game state.
	oManager->init();

	// Set up rendering.
	oRender->mSetUpRender();

	while (!SYS_GottaQuit()) {	// Controlling a request to terminate an application.

		oManager->LogicSlot(oTimer);

		// Render
		oRender->mRender(oTimer->currentTime, oTimer->frames, oTimer->logicTime);

		SYS_Pump();
	}

	oManager->deleteBalls();
	// End app.
	oManager->shutdownRender();
	// Unload textures.
	oManager->shutdown();

	
	return 0;
}
