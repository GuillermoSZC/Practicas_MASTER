#include "gameManager.h"
#include<iostream>
#include"timeCounter.h"
// extern tBalls balls;


void gameManager::LogicSlot(timeCounter* oTimer)
{
	oTimer->initSlotsToProcess();

	while (oTimer->processSlots())
	{
		// Logic
		balls->Slot(oTimer->getFixedTick(), balls, NUM_BALLS);
		// mLogic(oTimer->elapsedTime); // paso elapsed para el punto 2.7 de la practica

		oTimer->fixElapsed();
		// SYS_Sleep(17);
	}

	oTimer->calcFPS();
}