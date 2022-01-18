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
		// Logic
		oManager->LogicSlot(oTimer);

		// Render
		oRender->mRender(oTimer->getCurrentTime(), oTimer->getFrames(), oTimer->getLogicTime());

		SYS_Pump();
	}

	// End app.
	oRender->shutdownRender();
	// Unload textures.
	oManager->shutdown();

	delete oTimer;
	oTimer = nullptr;

	return 0;
}
