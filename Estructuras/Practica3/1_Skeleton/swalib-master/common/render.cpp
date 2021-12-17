#include "gameManager.h"
#include "Render.h"
#include <string>


// extern tBalls balls;

void Render::mRender(float time, float frames, float logicTime)
{
	gameManager* mg = gameManager::getInstance();
	// Render
	glClear(GL_COLOR_BUFFER_BIT);	// Clear color buffer to preset values.

	// Render backgground
	for (int i = 0; i <= SCR_WIDTH / 128; i++) {
		for (int j = 0; j <= SCR_HEIGHT / 128; j++) {
			CORE_RenderCenteredSprite(vec2(i * 128.f + 64.f, j * 128.f + 64.f), vec2(128.f, 128.f), mg->texbkg);
		}
	}

	// Render balls
	for (unsigned int i = 0; i < mg->NUM_BALLS; i++) {
		CORE_RenderCenteredSprite(mg->balls[i].getPos(), vec2(mg->balls[i].getRadius() * 2.f, mg->balls[i].getRadius() * 2.f), mg->balls[i].getGfx());
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

void Render::DrawString(std::string _name, int width, int height)
{
	FONT_DrawString(vec2(SCR_WIDTH / 2 - width, height), _name.c_str());
}