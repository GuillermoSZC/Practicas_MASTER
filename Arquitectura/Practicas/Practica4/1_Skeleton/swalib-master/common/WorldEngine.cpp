#include "WorldEngine.h"
#include"TimeCounter.h"
#include <iostream>
#include "stdafx.h"
#include "sys.h"
#include "core.h"

WorldEngine* WorldEngine::m_instance = nullptr; // inicializo la instancia del objeto singleton para poder usarlo

void WorldEngine::LoadImages()
{
	texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);
	texsmallball = CORE_LoadPNG("data/tyrian_ball.png", false);
}

void WorldEngine::CreateEntities()
{
	WorldEngine* objWorld = WorldEngine::getInstance();
	
		for (unsigned int i = 0; i < objWorld->NUM_BALLS; i++) {
			Entity* ball = new Ball();

			/*Set initial Transform */
			ball->FindComponent<C_Transform>()->SetPos(vec2(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT)));
			ball->FindComponent<C_Transform>()->SetVel(vec2(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED) * 10, CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED) * 10));

			/*Set radius and sprite*/
			ball->FindComponent<C_Collision>()->SetRadius(16.f);
			ball->FindComponent<C_Renderable>()->SetSprite(texsmallball);

			/*Set ID*/
			ball->SetID(objWorld->idEntity);

			objWorld->balls.push_back(ball);
			objWorld->idEntity++;
		}
}


void WorldEngine::LogicSlot(TimeCounter& _Time)
{
	_Time.initSlotsToProcess();

	while (_Time.processSlots()) // si elapsedTime es mayor o igual que fixedTick..
	{
		for (auto& _Entity : balls)
		{
			_Entity->Slot(_Time.getFixedTick());
		}
		_Time.fixElapsed();
		// SYS_Sleep(17);
	}
}

void WorldEngine::ShutdownRender()
{
	CORE_UnloadPNG(texbkg);
	CORE_UnloadPNG(texsmallball);
}

void WorldEngine::ShutdownEnt()
{
	for (auto& _Entity : balls)
	{
		delete _Entity;
		_Entity = nullptr;
	}
	balls.clear();
}