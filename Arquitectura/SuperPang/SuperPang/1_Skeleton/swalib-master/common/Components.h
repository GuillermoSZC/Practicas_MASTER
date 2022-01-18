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
	EntCollisionMsg* entCollMsg;
	HPMessages* hpMessages;

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

class C_CharactActions : public Component
{
private:
	vec2 pos;
	vec2 vel;
	int timer;

	NewPosMsg* newPositionMessage;
	NewVelMsg* newVelMessage;
	ShootMsg* auxMessage;

public:
	C_CharactActions();
	virtual ~C_CharactActions();


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
	void MoveLeft(float _Elapsed) { pos.x -= vel.x * _Elapsed * 2.f; }
	void MoveRight(float _Elapsed) { pos.x += vel.x * _Elapsed * 2.f; }

};

class C_ShotBullet : public Component
{
private:
	vec2 pos;
	vec2 vel;

	NewPosMsg* newPositionMessage;
	NewVelMsg* newVelMessage;
	ShootMsg* newShootMessage;

public:
	C_ShotBullet();
	virtual ~C_ShotBullet();
	
	// SETTERS 
	void SetPos(vec2& _Pos) { pos = _Pos; }
	void SetVel(vec2& _Vel) { vel = _Vel; }

	// GETTERS
	vec2& GetPos() { return pos; }
	vec2& GetVel() { return vel; }
	ShootMsg* GetShootMsg() { return newShootMessage; }

	// VIRTUAL FUNCTIONS
	virtual void Slot(float _Elapsed) override;
	virtual void ReceiveMessage(Message* _Message) override;

	// FUNCTIONS
	void MoveUp(float _Elapsed) { pos.y += vel.y * _Elapsed; }

};

class C_HealthComponent : public Component
{
private:
	int HP;

public:
	C_HealthComponent();
	virtual ~C_HealthComponent();

	void SetHP(int _hp); 

	int GetHP();

	// VIRTUAL FUNCTIONS
	virtual void Slot(float _Elapsed) override;
	virtual void ReceiveMessage(Message* _Message) override;
};