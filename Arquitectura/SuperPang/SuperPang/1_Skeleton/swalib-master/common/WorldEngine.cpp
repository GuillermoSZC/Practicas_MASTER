#include "WorldEngine.h"
#include "RenderEngine.h"
#include"TimeCounter.h"
#include <iostream>
#include "stdafx.h"
#include "sys.h"
#include "core.h"

WorldEngine* WorldEngine::m_instance = nullptr; // inicializo la instancia del objeto singleton para poder usarlo

WorldEngine::WorldEngine() : NUM_BALLS(8), NUM_BULLETS(20), MAX_BALL_SPEED(15.f), dist(0.f)
{
	texsmallball = 0;
	texbkg = 0;
	background = 0;
	texcharacter = 0;
	texbullet = 0;
	idEntity = 0;
}

void WorldEngine::LoadImages()
{
	texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);
	background = CORE_LoadPNG("data/fondo.png", true);
	texsmallball = CORE_LoadPNG("data/tyrian_ball.png", false);
	texcharacter = CORE_LoadPNG("data/personaje.png", false);
	texbullet = CORE_LoadPNG("data/bullet.png", false);
}

void WorldEngine::CreateEntities()
{
	WorldEngine* objWorld = WorldEngine::getInstance();

	Entity* character = new Character;
	character->FindComponent<C_Renderable>()->SetSprite(texcharacter);
	character->FindComponent<C_HealthComponent>()->SetHP(3);
	character->FindComponent<C_Collision>()->SetRadius(32.f);
	character->SetName("character");

	objWorld->entities.push_back(character);
	objWorld->idEntity++;

	for (unsigned int i = 0; i < objWorld->NUM_BALLS; i++) {
		Entity* ball = new Ball();

		/*Set initial Transform */
		ball->FindComponent<C_Transform>()->SetPos(vec2(25.f + objWorld->GetDist(), CORE_FRand(240.0f, SCR_HEIGHT)));
		ball->FindComponent<C_Transform>()->SetVel(vec2(0.f, 20 * 10));

		/*Set radius and sprite*/
		ball->FindComponent<C_Collision>()->SetRadius(CORE_FRand(16.0, 48.0));
		ball->FindComponent<C_HealthComponent>()->SetHP(1);
		ball->FindComponent<C_Renderable>()->SetSprite(texsmallball);

		/*Set ID*/
		ball->SetID(objWorld->idEntity);
		ball->Activated(true);
		ball->SetName("ball");

		objWorld->entities.push_back(ball);
		objWorld->idEntity++;
		objWorld->ExpandDist();
	}

	// Set bullet 
	for (unsigned int i = 0; i < NUM_BULLETS; i++)
	{
		Entity* bullet = new Bullet;

		bullet->FindComponent<C_Collision>()->SetRadius(32.f);
		bullet->FindComponent<C_Renderable>()->SetSprite(texbullet);

		bullet->SetID(objWorld->idEntity);
		bullet->Activated(false);
		bullet->SetName("bullet");

		objWorld->entities.push_back(bullet);
		objWorld->idEntity++;
	}
}

void WorldEngine::LogicSlot(TimeCounter& _Time)
{
	
	_Time.initSlotsToProcess();

	while (_Time.processSlots()) // si elapsedTime es mayor o igual que fixedTick..
	{
		if (SYS_KeyPressed(SYS_MB_MIDDLE)) // click middle mouse button to exit 
		{
			exit(0);
		}
		for (auto& _Entity : entities)
		{
			if (_Entity->GetActive())
			{
				_Entity->Slot(_Time.getFixedTick());
			}
		}
		_Time.fixElapsed();
	}
}

void WorldEngine::ShutdownRender()
{
	CORE_UnloadPNG(texbkg);
	CORE_UnloadPNG(texsmallball);
	CORE_UnloadPNG(texcharacter);
	CORE_UnloadPNG(texbullet);
	CORE_UnloadPNG(background);
}

void WorldEngine::ShutdownEnt()
{
	for (auto& _Entity : entities)
	{
		delete _Entity;
		_Entity = nullptr;
	}
	entities.clear();
}

void WorldEngine::ExpandDist()
{
	dist += CORE_FRand(50.0, 110.0);
}