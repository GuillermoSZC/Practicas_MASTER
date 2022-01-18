#pragma once 

class TimeCounter
{
private:
	float currentTime;
	float fixedTick;
	float elapsedTime;
	float frames;
	float frameRate;
	float currentFps;
	float logicTime;
	float capTime; // tiempo limite para evitar espiral de la muerte

public:
	TimeCounter();
	~TimeCounter();

	// GETTERS
	float getCurrentTime() ;
	float getFixedTick() const;
	float getElapsedTime();
	float getFrames(); 
	float getFrameRate(); 
	float getCurrentFps(); 
	float getLogicTime(); 
	float getCapTime() const;

	// FUNCTIONS
	void initSlotsToProcess();
	bool processSlots();
	void fixElapsed();
	void StartCounter();
	float GetTime();
};