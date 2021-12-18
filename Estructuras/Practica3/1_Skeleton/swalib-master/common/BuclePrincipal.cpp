#include "WorldEngine.h"
#include<iostream>
#include"RenderEngine.h"

int Main(void)
{
	WorldEngine* oManager = WorldEngine::getInstance();
	TimeCounter* oTimer = new TimeCounter();
	RenderEngine* oRender = RenderEngine::getInstance();

	oTimer->StartCounter();

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

	// End app.
	oManager->shutdownRender();
	// Unload textures.
	oManager->shutdown();

	return 0;
}
