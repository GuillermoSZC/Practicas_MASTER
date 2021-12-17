#include "timeCounter.h"
#include "stdafx.h"
#include<iostream>

__int64 counterStart = 0;
float frec = 0.f;

timeCounter::timeCounter()
{
	currentTime = 0.f;
	fixedTick = 1.f / 60.f;
	elapsedTime = 0.f;
	frames = 0.f;
	prevFps = 0.f;
	currentFps = 0.f;
	logicTime = 0.f;
	capTime = 1.f / 15.f;
}
timeCounter::~timeCounter() { printf("obj timeCounter deleted.\n"); } // Destructor

float timeCounter::getCurrentTime() { return currentTime; }
float timeCounter::getFixedTick() const { return fixedTick; }
float timeCounter::getElapsedTime() { return elapsedTime; }
float timeCounter::getFrames() { return frames; }
float timeCounter::getPrevFps() { return prevFps; }
float timeCounter::getCurrentFps() { return currentFps; }
float timeCounter::getLogicTime() { return logicTime; }
float timeCounter::getCapTime() const { return capTime; }

void timeCounter::initSlotsToProcess()
{
	elapsedTime += GetTime();
	currentTime += fixedTick;
	//elapsedTime = currentTime*1.5 - previousTime*1.5; // ? mult 1.5f porque??
	//previousTime = currentTime;
}

bool timeCounter::processSlots()
{
	return elapsedTime >= fixedTick ? true : false;
}

void timeCounter::initPrevs()
{
	prevFps = GetTime();
}

void timeCounter::fixElapsed() // @TODO:
{
	if (elapsedTime >= capTime)
	{ // si ha superado el limite lo igualo a fixedTick
		elapsedTime = fixedTick;
	}
	else
	{
		elapsedTime -= fixedTick;
	}
	logicTime += fixedTick;
	currentFps++;
}

void timeCounter::calcFPS() // @TODO: CALCULAR FRAMES
{

	if (currentTime - prevFps >= 1.0f)
	{
		frames = currentFps;
		currentFps = 0.f;
		prevFps++;
	}
}

void timeCounter::StartCounter()
{

	LARGE_INTEGER li;

	// Performance counter
	if (QueryPerformanceFrequency(&li))
	{
		std::cout << "Frequency failed\n";
	}
	frec = float(li.QuadPart);

	QueryPerformanceCounter(&li);
	counterStart = li.QuadPart;
	elapsedTime = 0.0f;
}

// Elapsed
float timeCounter::GetTime()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	float time = float(li.QuadPart - counterStart);
	counterStart = li.QuadPart;

	return time / frec;
}