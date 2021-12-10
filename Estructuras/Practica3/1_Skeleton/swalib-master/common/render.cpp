#include "gameManager.h"
#include <string>

extern tBalls balls;

void gameManager::mRender(float time, float frames, float logicTime)
{
	// Render
	glClear(GL_COLOR_BUFFER_BIT);	// Clear color buffer to preset values.

	// Render backgground
	for (int i = 0; i <= SCR_WIDTH / 128; i++) {
		for (int j = 0; j <= SCR_HEIGHT / 128; j++) {
			CORE_RenderCenteredSprite(vec2(i * 128.f + 64.f, j * 128.f + 64.f), vec2(128.f, 128.f), texbkg);
		}
	}

	// Render balls
	for (unsigned int i = 0; i < NUM_BALLS; i++) {
		CORE_RenderCenteredSprite(balls[i].pos, vec2(balls[i].radius * 2.f, balls[i].radius * 2.f), balls[i].gfx);
	}

	std::string sTime = std::to_string((int)time);
	
	std::string	sFrames = std::to_string((int)frames);

	std::string	sLogicTime = std::to_string((int)logicTime);
	
	// Text

	FONT_DrawString(vec2(SCR_WIDTH / 2 - 6 * 16, 16), "HELLO WORLD!");
	std::string sCad = "TIME: " + sTime;
	FONT_DrawString(vec2(SCR_WIDTH / 2 - 300, 450), sCad.c_str());
	sCad = "FPS: " + sFrames;
	FONT_DrawString(vec2(SCR_WIDTH / 2 - -190, 450), sCad.c_str());
	sCad = "L-TIME: " + sLogicTime;
	FONT_DrawString(vec2(SCR_WIDTH / 2 - 300, 420), sCad.c_str());
	


	// Exchanges the front and back buffers
	SYS_Show();
}