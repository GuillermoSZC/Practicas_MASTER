#include "gameManager.h"

void gameManager::shutdownRender()
{
	CORE_UnloadPNG(texbkg);
	CORE_UnloadPNG(texsmallball);
}