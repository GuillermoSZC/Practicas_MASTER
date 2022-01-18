#include<iostream>
#include"RenderEngine.h"
#include"TimeCounter.h"
#include"WorldEngine.h"
#include "sys.h"

int Main(void)
{
	TimeCounter* oTimer = new TimeCounter();

	WorldEngine* oManager = WorldEngine::getInstance();
	RenderEngine* oRender = RenderEngine::getInstance();

	oTimer->StartCounter();
	// Init game state.
	oRender->RenderInit();

	while (!SYS_GottaQuit()) // Controlling a request to terminate an application.
	{	
		// Logic
		oManager->LogicSlot(*oTimer);
		// Render
		oRender->Render(oTimer->getCurrentTime(), oTimer->getFrames(), oTimer->getLogicTime());
		SYS_Pump();
	}

	// End app.
	oRender->Shutdown();

	delete oTimer;
	oTimer = nullptr;

	return 0;
}
