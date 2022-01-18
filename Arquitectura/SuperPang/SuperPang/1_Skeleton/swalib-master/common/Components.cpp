#include "Components.h"
#include "WorldEngine.h"
#include "RenderEngine.h"
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
	newPositionMessage->SetNewPos(GetPos()); // guarda la posicion actual dentro de la posicion del objeto NewPosMsg
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
	collisionMessage = new CollisionMsg();
	limitWorldCollisionMsg = new LimitWorldCollMsg();
	entCollMsg = new EntCollisionMsg();
	hpMessages = new HPMessages();
}

C_Collision::~C_Collision()
{
	delete collisionMessage;
	collisionMessage = nullptr;

	delete limitWorldCollisionMsg;
	limitWorldCollisionMsg = nullptr;

	delete entCollMsg;
	entCollMsg = nullptr;

	delete entCollMsg;
	entCollMsg = nullptr;
}

bool C_Collision::HasCollided(Entity* _Entity)
{
	if (this->oOwner == _Entity)
	{
		return false;
	}

	if (_Entity->GetActive())
	{
		float dist = (GetRadius() + _Entity->FindComponent<C_Collision>()->GetRadius())
			* (GetRadius() + _Entity->FindComponent<C_Collision>()->GetRadius());

		if (vlen2(GetPos() - _Entity->FindComponent<C_Transform>()->GetPos()) <= dist)
		{
			return true;
		}
	}
	return false;
}

void C_Collision::Slot(float _Elapsed)
{
	for (auto& _Entity : WorldEngine::getInstance()->entities)
	{
		if (HasCollided(_Entity))
		{
			collisionMessage->SetCollision(true);
			collisionMessage->entity = _Entity;

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
		}
		else
		{
			oOwner->SendMsg(entCollMsg);
		}
	}

	EntCollisionMsg* entCollisionMsg = dynamic_cast<EntCollisionMsg*>(_Message);
	if (entCollisionMsg)
	{
		if (oOwner->GetName() == "bullet" && collisionMessage->entity->GetName() == "ball")
		{
			oOwner->Activated(false);
			collisionMessage->entity->Activated(false);
		}
		if (oOwner->GetName() == "character" && collisionMessage->entity->GetName() == "ball")
		{
			if (hpMessages->GetHP() == 0)
			{
				
				oOwner->SendMsg(hpMessages);
			}
			else
			{
				collisionMessage->entity->Activated(false);
				hpMessages->DecreaseHP();
				oOwner->SendMsg(hpMessages);
			}
		}
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
			NewVelMsg* _Message = new NewVelMsg(vec2(GetVel().x, GetVel().y * -1.f));
			oOwner->SendMsg(_Message);

			delete _Message;
			_Message = nullptr;
		}
	}
}
#pragma endregion

#pragma region C_CharactActions

C_CharactActions::C_CharactActions() : timer(0)
{
	newPositionMessage = new NewPosMsg(GetPos());
	newVelMessage = new NewVelMsg(GetVel());
	auxMessage = new ShootMsg();
}

C_CharactActions::~C_CharactActions()
{
	delete newPositionMessage;
	newPositionMessage = nullptr;
	delete newVelMessage;
	newVelMessage = nullptr;
	delete auxMessage;
	auxMessage = nullptr;
}

void C_CharactActions::Slot(float _Elapsed)
{
	if (SYS_KeyPressed(SYS_KEY_LEFT))
	{
		if (GetPos().x > 0)
		{
			MoveLeft(_Elapsed);
		}
	}
	else if (SYS_KeyPressed(SYS_KEY_RIGHT)) 
	{
		if (GetPos().x < SCR_WIDTH)
		{
			MoveRight(_Elapsed);
		}
	} 
	else if (SYS_KeyPressed(SYS_KEY_UP))
	{
		for (auto& ent : WorldEngine::getInstance()->entities)
		{
			if (!ent->GetActive() && ent->GetName() == "bullet" && timer > 0)
			{
				auxMessage = ent->FindComponent<C_ShotBullet>()->GetShootMsg();
				auxMessage->SetPos(GetPos());
				ent->SendMsg(auxMessage);
				timer = 0;
			}
		}
	}
	timer = 1;

	newPositionMessage->SetNewPos(GetPos());
	oOwner->SendMsg(newPositionMessage);

	newVelMessage->SetNewVel(GetVel());
	oOwner->SendMsg(newVelMessage);
}

void C_CharactActions::ReceiveMessage(Message* _Message)
{

}

#pragma endregion

#pragma region C_ShotBullet

C_ShotBullet::C_ShotBullet() : vel(450)
{
	newPositionMessage = new NewPosMsg(GetPos());
	newVelMessage = new NewVelMsg(GetVel());
	newShootMessage = new ShootMsg(GetPos());
}

C_ShotBullet::~C_ShotBullet()
{
	delete newPositionMessage;
	newPositionMessage = nullptr;
	delete newVelMessage;
	newVelMessage = nullptr;
}

void C_ShotBullet::Slot(float _Elapsed)
{

	if (GetPos().y < SCR_HEIGHT && oOwner->GetActive())
	{
		MoveUp(_Elapsed);
	}
	else
	{
		oOwner->Activated(false);
	}
	
	newPositionMessage->SetNewPos(GetPos());
	oOwner->SendMsg(newPositionMessage);

	newVelMessage->SetNewVel(GetVel());
	oOwner->SendMsg(newVelMessage);
}

void C_ShotBullet::ReceiveMessage(Message* _Message)
{
	ShootMsg* characPosMsg = dynamic_cast<ShootMsg*>(_Message);
	
	if (characPosMsg)
	{
		SetPos(vec2(characPosMsg->GetPos().x, characPosMsg->GetPos().y + 50));
		oOwner->Activated(true);
	}
}
#pragma endregion

#pragma region C_HealthComponent

C_HealthComponent::C_HealthComponent() : HP(0) { }
C_HealthComponent::~C_HealthComponent() { }

void C_HealthComponent::SetHP(int _hp)
{ 
	HP = _hp;
}

int C_HealthComponent::GetHP()
{
	return HP; 
}

void C_HealthComponent::Slot(float _Elapsed) { }

void C_HealthComponent::ReceiveMessage(Message* _Message)
{
	HPMessages* hpMsg = dynamic_cast<HPMessages*>(_Message);

	if (hpMsg)
	{
		SetHP(hpMsg->GetHP());
		if (GetHP() < 1)
		{
			for (auto& ent : WorldEngine::getInstance()->entities)
			{
				ent->Activated(false);
			}
		}
	}
}

#pragma endregion