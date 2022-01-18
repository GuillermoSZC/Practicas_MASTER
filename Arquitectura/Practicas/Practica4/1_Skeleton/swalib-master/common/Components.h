#pragma once
#pragma region Manager Includes
#include "EntityComponent.h"
#include "MessageManager.h"
#include "TimeCounter.h"
#pragma endregion
#include "vector2d.h"
#include "stdafx.h"

class C_Renderable : public Component
{
private:
	GLuint gfx = 0;

public:
	// CONSTRUCTOR & DESTRUCTOR
	C_Renderable() {}
	virtual ~C_Renderable() {}

	// SETTERS
	void SetSprite(GLuint& _Sprite);
	void SetSprite(const char* _FileName, bool _Val);

	// GETTERS
	GLuint GetSprite() { return gfx; }
	
	// VIRTUAL FUNCTIONS
	virtual void Slot(float _Elapsed) override {};
	virtual void ReceiveMessage(Message* _Message) override {};

};

class C_Transform : public Component
{
private:
	vec2 vel;
	vec2 pos;
	// Puntero a NewPosMsg -- MessageManager
	NewPosMsg* newPositionMessage;

public:
	// CONSTRUCTOR & DESTRUCTOR
	C_Transform();
	virtual ~C_Transform();

	// SETTERS 
	void SetPos(vec2& _Pos) { pos = _Pos; }
	void SetVel(vec2& _Vel) { vel = _Vel; }

	// GETTERS
	vec2& GetPos() { return pos; }
	vec2& GetVel() { return vel; }

	// VIRTUAL FUNCTIONS
	virtual void Slot(float _Elapsed) override;
	virtual void ReceiveMessage(Message* _Message) override;

	// FUNCTIONS
	void UpdatePosition(float& _Elapsed) { pos += vel * _Elapsed; }

};

class C_Collision : public Component
{
private:
	float radius = 0;
	vec2 pos;

	// Punteros a CollisionMsg y LimitWorldCollMsg -- MessageManager
	CollisionMsg* collisionMessage;
	LimitWorldCollMsg* limitWorldCollisionMsg;

public:
	// CONSTRUCTOR & DESTRUCTOR
	C_Collision();
	virtual ~C_Collision();

	// SETTERS
	void SetRadius(float _Radius) { radius = _Radius; }
	// void setPos(float _Pos) { pos = _Pos; }

	// GETTERS
	vec2& GetPos() { return oOwner->FindComponent<C_Transform>()->GetPos(); }
	vec2& GetVel() { return oOwner->FindComponent<C_Transform>()->GetVel(); }
	float& GetRadius() { return radius; }

	// VIRTUAL FUNCTIONS
	virtual void Slot(float _Elapsed) override;
	virtual void ReceiveMessage(Message* _Message) override;

	// FUNCTIONS
	bool HasCollided(Entity* _Entity);
};

