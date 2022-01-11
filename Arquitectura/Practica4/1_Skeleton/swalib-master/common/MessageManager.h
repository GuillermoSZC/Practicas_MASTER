#pragma once
#include "sys.h"
#include "vector2d.h"
#include "EntityComponent.h"

class Message
{
public:
	Message() {}
	virtual ~Message() {}
};

#pragma region COLLISION MESSAGES
class CollisionMsg : public Message
{
private:
		bool bCollision;
		int indexCollision;

public:
		CollisionMsg() : bCollision(false), indexCollision(-1) { }
		CollisionMsg(bool coll, int index) : bCollision(coll), indexCollision(index) {}
		virtual ~CollisionMsg() { }

		// SETTERS
		void SetCollision(bool _Collision) { bCollision = _Collision; }
		void SetIndex(int _Index) { indexCollision = _Index; }

		// GETTERS
		bool GetCollision() { return bCollision; }
		int GetIndex() { return indexCollision; }
};

class EntCollisionMsg : public CollisionMsg
{
private:
	float fRebound;

public:
	EntCollisionMsg() : fRebound(-1.f) { }
	virtual ~EntCollisionMsg() { }

	// SETTER
	void SetRebound(float _Rebound) { fRebound = _Rebound; }

	// GETTER
	float GetRebound() { return fRebound; }
};

class LimitWorldCollMsg : public CollisionMsg
{
private:
	const int widthLimit;
	const int heightLimit;

public:
	LimitWorldCollMsg() : widthLimit(SCR_WIDTH), heightLimit(SCR_HEIGHT) { }
	virtual ~LimitWorldCollMsg() { }

	// GETTER
	const int GetWidth() const { return widthLimit; }
	const int GetHeight() const { return heightLimit; }
};
#pragma endregion

#pragma region TRANSFORM MESSAGES
class NewPosMsg : public Message
{
private:
	vec2 pos;

public:
	NewPosMsg() { }
	NewPosMsg(vec2& _NewPos) : pos(_NewPos) { }
	virtual ~NewPosMsg() { }

	// SETTER
	void SetNewPos(vec2 _Pos) { pos = _Pos; }

	// GETTER
	vec2 GetNewPos() { return pos;}
};


class NewVelMsg : public Message
{
private:
	vec2 vel;

public:

	NewVelMsg() { }
	NewVelMsg(vec2& _NewVel) : vel(_NewVel) { }
	virtual ~NewVelMsg() { }

	// SETTER
	void SetNewVel(vec2 _Vel) { vel = _Vel; }

	// GETTER
	vec2 GetNewVel() { return vel; }

};
#pragma endregion
