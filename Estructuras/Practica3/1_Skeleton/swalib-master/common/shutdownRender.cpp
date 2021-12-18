#include "WorldEngine.h"

void WorldEngine::shutdownRender()
{
	CORE_UnloadPNG(texbkg);
	CORE_UnloadPNG(texsmallball);
}