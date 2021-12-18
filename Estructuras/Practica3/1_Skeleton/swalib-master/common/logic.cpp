#include "WorldEngine.h"
#include<iostream>
#include"TimeCounter.h"


void WorldEngine::LogicSlot(TimeCounter* oTimer)
{
	oTimer->initSlotsToProcess();

	while (oTimer->processSlots()) // si elapsedTime es mayor o igual que fixedTick..
	{
		balls->Slot(oTimer->getFixedTick(), balls, NUM_BALLS);
		oTimer->fixElapsed();
		// SYS_Sleep(17);
	}
}