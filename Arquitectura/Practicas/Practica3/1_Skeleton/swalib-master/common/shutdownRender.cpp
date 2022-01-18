#include "WorldEngine.h"
#include "RenderEngine.h"

void RenderEngine::shutdownRender()
{
	CORE_UnloadPNG(WorldEngine::getInstance()->texbkg);
	CORE_UnloadPNG(WorldEngine::getInstance()->texsmallball);
}