#include "TimeCounter.h"
#include<iostream>
#include "stdafx.h"

__int64 counterStart = 0;
float frec = 0.f;

TimeCounter::TimeCounter()
{
	currentTime = 0.f;
	fixedTick = 1.f / 60.f;
	elapsedTime = 0.f;
	frames = 0.f;
	frameRate = 0.f;
	currentFps = 0.f;
	logicTime = 0.f;
	capTime = 1.f / 15.f;
}
TimeCounter::~TimeCounter() { printf("obj timeCounter deleted.\n"); } // Destructor

// getters
float TimeCounter::getCurrentTime()  { return currentTime; }
float TimeCounter::getFixedTick() const { return fixedTick; }
float TimeCounter::getElapsedTime()  { return elapsedTime; }
float TimeCounter::getFrames()  { return frames; }
float TimeCounter::getFrameRate()    { return frameRate; }
float TimeCounter::getCurrentFps()   { return currentFps; }
float TimeCounter::getLogicTime()  { return logicTime; }
float TimeCounter::getCapTime() const { return capTime; }

void TimeCounter::initSlotsToProcess()
{
	elapsedTime += GetTime();
	currentTime += fixedTick;
	
	if (currentTime - frameRate >= 1.0f) // calculo los frames
	{
		frames = currentFps;
		currentFps = 0.f;
		frameRate++;
	}
} // funcion que va calculando el elapsedTime, el currentTime y los frames cada vez que se le llama

bool TimeCounter::processSlots()
{
	return elapsedTime >= fixedTick ? true : false;
}

void TimeCounter::fixElapsed() 
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

void TimeCounter::StartCounter()
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

	// srand(time(NULL)); 
}

// Elapsed
float TimeCounter::GetTime()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	float time = float(li.QuadPart - counterStart);
	counterStart = li.QuadPart;

	return time / frec;
}