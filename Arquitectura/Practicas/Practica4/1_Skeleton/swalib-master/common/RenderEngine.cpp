#include <string>
#pragma region MANAGER INCLUDES
#include "WorldEngine.h"
#include "RenderEngine.h"
#include "Components.h"
#pragma endregion
#pragma region ENGINE INCLUDES
#include "stdafx.h"
#include "font.h"
#include "vector2d.h"
#include "core.h"
#include "sys.h"
#pragma endregion

RenderEngine* RenderEngine::instance = nullptr;

void RenderEngine::SetUpRender()
{
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT); // Sets up clipping.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Specifies clear values for the color buffers.
	glMatrixMode(GL_PROJECTION);	// Specifies projection matrix is the current matrix.
	glLoadIdentity();	// Replaces the current matrix with the identity matrix.
	glOrtho(0.0, SCR_WIDTH, 0.0, SCR_HEIGHT, 0.0, 1.0);	// Multiplies the current matrix by an orthographic matrix.
	glEnable(GL_TEXTURE_2D);	// Enabling two-dimensional texturing.
	// NOTA: Mirar diferencias comentando las 2 siguientes funciones.
	glEnable(GL_BLEND);	// Blend the incoming RGBA color values with the values in the color buffers.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	// Blend func. for alpha color.
}

void RenderEngine::RenderInit()
{
	FONT_Init();
	// cargo las imagenes
	WorldEngine::getInstance()->LoadImages();
	// creo las entidades
	WorldEngine::getInstance()->CreateEntities();

	SetUpRender();
}

void RenderEngine::Render(float time, float frames, float logicTime)
{
	WorldEngine* objWorldManager = WorldEngine::getInstance();
	// Render
	glClear(GL_COLOR_BUFFER_BIT);	// Clear color buffer to preset values.

	// Render backgground
	for (int i = 0; i <= SCR_WIDTH / 128; i++) {
		for (int j = 0; j <= SCR_HEIGHT / 128; j++) {
			CORE_RenderCenteredSprite(vec2(i * 128.f + 64.f, j * 128.f + 64.f), vec2(128.f, 128.f), objWorldManager->GetTexbkg());
		}
	}

	// Render balls
	for (unsigned int i = 0; i < objWorldManager->balls.size(); i++) {
		CORE_RenderCenteredSprite(objWorldManager->balls[i]->FindComponent<C_Transform>()->GetPos(),
			vec2(objWorldManager->balls[i]->FindComponent<C_Collision>()->GetRadius() * 2.f,
			objWorldManager->balls[i]->FindComponent<C_Collision>()->GetRadius() * 2.f), 
			objWorldManager->balls[i]->FindComponent<C_Renderable>()->GetSprite());
	}

	std::string sTime = std::to_string((int)time);
	
	std::string	sFrames = std::to_string((int)frames);

	std::string	sLogicTime = std::to_string((int)logicTime);
	
	// Text
	DrawString("HELLO WORLD!", 96, 16);
	std::string sCad = "TIME: " + sTime;
	DrawString(sCad, 300, 450);
	sCad = "FPS: " + sFrames;
	DrawString(sCad, -190, 450);
	sCad = "L-TIME: " + sLogicTime;
	DrawString(sCad, 300, 420);

	// Exchanges the front and back buffers
	SYS_Show();
}

void RenderEngine::DrawString(std::string _name, int width, int height)
{
	FONT_DrawString(vec2(SCR_WIDTH / 2 - (float)width, (float)height), _name.c_str());
} // metodo para pintar strings como sprites

void RenderEngine::Shutdown()
{
	WorldEngine::getInstance()->ShutdownRender();
	WorldEngine::getInstance()->ShutdownEnt();
	FONT_End();
}