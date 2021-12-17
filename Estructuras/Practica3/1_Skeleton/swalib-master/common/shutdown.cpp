#include "gameManager.h"

void gameManager::shutdown()
{
	FONT_End();
}

void gameManager::deleteBalls()
{
	delete balls;
}
