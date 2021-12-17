#pragma once 

class timeCounter
{
public:
	float currentTime;
	float fixedTick;
	float elapsedTime;
	float frames;
	float prevFps;
	float currentFps;
	float logicTime;
	float capTime; // tiempo limite para evitar espiral de la muerte

	timeCounter();
	~timeCounter();

	float getCurrentTime();
	float getFixedTick() const;
	float getElapsedTime();
	float getFrames();
	float getPrevFps();
	float getCurrentFps();
	float getLogicTime();
	float getCapTime() const;


	void initSlotsToProcess();
	bool processSlots();
	void initPrevs();
	void fixElapsed();
	void calcFPS();
	void StartCounter();
	float GetTime();

};