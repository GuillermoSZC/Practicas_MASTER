#pragma once
#include "sys.h"
#include "vector2d.h"
#include "EntityComponent.h"

class Entity;
class Message;

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
		bool bCollision = false;
		int indexCollision = -1;

public:
		CollisionMsg() { }
		CollisionMsg(bool coll, int index) : bCollision(coll), indexCollision(index) {}


		Entity* entity = nullptr;

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


public:
	EntCollisionMsg() { }
	virtual ~EntCollisionMsg() { }

	
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

#pragma region ShootMsg

class ShootMsg : public Message
{
private:
	vec2 pos;

public:
	ShootMsg() { }
	ShootMsg(vec2& _Pos) : pos(_Pos) {  }
	virtual ~ShootMsg() {}

	// SETTER
	void SetPos(vec2 _Pos) { pos = _Pos; }

	// GETTER
	vec2 GetPos() { return pos; }

};

#pragma endregion

class HPMessages : public Message
{
private:
	int HP;

public:
	HPMessages() : HP(3) { }
	virtual ~HPMessages() { }

	void SetHP(int _HP) { HP = _HP; }

	int GetHP() { return HP; }

	void DecreaseHP() { HP--; }

};

