#include "gameManager.h"

int Main(void)
{
	gameManager* oManager = new gameManager(); // Create obj gameManager()

	// Init game state.
	oManager->init();

	// Set up rendering.
	oManager->mSetUpRender();
  
	while (!SYS_GottaQuit()) {	// Controlling a request to terminate an application.
		// Render
		oManager->mRender();

		// Logic
		oManager->mLogic();
		
		SYS_Pump();	// Process Windows messages.
		SYS_Sleep(17);	// To force 60 fps
	}

	// End app.
	oManager->shutdownRender();
	// Unload textures.
	oManager->shutdown();

	
	delete oManager; // Delete obj gameManager()

	return 0;
}