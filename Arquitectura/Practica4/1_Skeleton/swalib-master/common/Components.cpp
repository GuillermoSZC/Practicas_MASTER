#include "Components.h"
#include "WorldEngine.h"
#include "core.h"
#include "sys.h"

#pragma region C_Renderable
void C_Renderable::SetSprite(GLuint& _Sprite)
{
	gfx = _Sprite;
}

void C_Renderable::SetSprite(const char* _FileName, bool _Val)
{
	gfx = CORE_LoadPNG(_FileName, _Val);
}
#pragma endregion

#pragma region C_Transform
C_Transform::C_Transform()
{
	newPositionMessage = new NewPosMsg(GetPos());
}

C_Transform::~C_Transform()
{
	delete newPositionMessage;
	newPositionMessage = nullptr;
}

void C_Transform::Slot(float _Elapsed)
{
	UpdatePosition(_Elapsed); // Actualiza la posicion con el elapsed
	newPositionMessage->SetNewPos(GetPos()); // guarda la posicion actual dentro de la posicion de la posicion del objeto NewPosMsg
	oOwner->SendMsg(newPositionMessage); // envia el mensaje pasando el newPositionMessage
}

void C_Transform::ReceiveMessage(Message* _Message)
{
	// Cuando recibe el mensaje..
	//
	// Establece la nueva posicion: 
	NewPosMsg* newPosition = dynamic_cast<NewPosMsg*>(_Message);
	if (newPosition) 
	{ 
		SetPos(newPosition->GetNewPos());
	}

	// Establece la nueva velocidad: 
	NewVelMsg* newVelocity = dynamic_cast<NewVelMsg*>(_Message);
	if (newVelocity)
	{
		SetVel(newVelocity->GetNewVel());
	}
}
#pragma endregion

#pragma region C_Collision

C_Collision::C_Collision()
{
	collisionMessage = new CollisionMsg(false, -1);
	limitWorldCollisionMsg = new LimitWorldCollMsg();
}

C_Collision::~C_Collision()
{
	delete collisionMessage;
	collisionMessage = nullptr;

	delete limitWorldCollisionMsg;
	limitWorldCollisionMsg = nullptr;
}

bool C_Collision::HasCollided(Entity* _Entity)
{
	WorldEngine* objWorldManager = WorldEngine::getInstance();

	float dist = (GetRadius() + objWorldManager->balls[_Entity->GetID()]->FindComponent<C_Collision>()->GetRadius())
		* (GetRadius() + objWorldManager->balls[_Entity->GetID()]->FindComponent<C_Collision>()->GetRadius());

	if (this->oOwner != _Entity)
	{
		if (vlen2(GetPos() - objWorldManager->balls[_Entity->GetID()]->FindComponent<C_Transform>()->GetPos()) <= dist)
		{
			return true;
		}
	}
	return false;
}

void C_Collision::Slot(float _Elapsed)
{
	for (auto& _Entity : WorldEngine::getInstance()->balls)
	{
		if (HasCollided(_Entity))
		{
			collisionMessage->SetCollision(true);
			collisionMessage->SetIndex(_Entity->GetID());

			oOwner->SendMsg(collisionMessage);
			break;
		}
	}
	oOwner->SendMsg(limitWorldCollisionMsg);
}

void C_Collision::ReceiveMessage(Message* _Message)
{
	CollisionMsg* collisionMsg = dynamic_cast<CollisionMsg*>(_Message);
	if (collisionMsg)
	{
		if (!collisionMsg->GetCollision())
		{
			NewPosMsg* _Message = new NewPosMsg(GetPos());
			oOwner->SendMsg(_Message);

			delete _Message;
			_Message = nullptr;
		}
		else
		{
			EntCollisionMsg* _Message = new EntCollisionMsg();
			oOwner->SendMsg(_Message);

			delete _Message;
			_Message = nullptr;
		}
	}

	EntCollisionMsg* entCollisionMsg = dynamic_cast<EntCollisionMsg*>(_Message);
	if (entCollisionMsg)
	{
		NewVelMsg* _VelMessage = new NewVelMsg(GetVel() * entCollisionMsg->GetRebound());
		oOwner->SendMsg(_VelMessage);

		delete _VelMessage;
		_VelMessage = nullptr;
	}

	LimitWorldCollMsg* limitWorldMsg = dynamic_cast<LimitWorldCollMsg*>(_Message);
	if (limitWorldMsg)
	{
		if ((GetPos().x > limitWorldMsg->GetWidth()) || (GetPos().x < 0))
		{
			NewVelMsg* _Message = new NewVelMsg(vec2(GetVel().x * -1.0f, GetVel().y));
			oOwner->SendMsg(_Message);

			delete _Message;
			_Message = nullptr;
		}
		if ((GetPos().y > limitWorldMsg->GetHeight()) || (GetPos().y < 0))
		{
			NewVelMsg* _Message = new NewVelMsg(vec2(GetVel().x, GetVel().y * -1.0f));
			oOwner->SendMsg(_Message);

			delete _Message;
			_Message = nullptr;
		}
	}
}
#pragma endregion