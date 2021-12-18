#pragma once 

class TimeCounter
{
public:
	float currentTime;
	float fixedTick;
	float elapsedTime;
	float frames;
	float frameRate;
	float currentFps;
	float logicTime;
	float capTime; // tiempo limite para evitar espiral de la muerte

	TimeCounter();
	~TimeCounter();

	float getCurrentTime() ;
	float getFixedTick() const;
	float getElapsedTime();
	float getFrames(); 
	float getPrevFps(); 
	float getCurrentFps(); 
	float getLogicTime(); 
	float getCapTime() const;


	void initSlotsToProcess();
	bool processSlots();
	void fixElapsed();
	void StartCounter();
	float GetTime();

};