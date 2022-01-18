#include "EntityComponent.h"

Component::Component()
{
	oOwner = new Entity();
}

Entity::~Entity()
{
	for (auto& _Component : ovComponents)
	{
		delete _Component;
		_Component = nullptr;
	}
	ovComponents.clear();
}

void Entity::Slot(float _Elapsed)
{
	for (auto& _Component : ovComponents)
	{
		_Component->Slot(_Elapsed);
	}
}

void Entity::AddComponent(Component* _Component)
{
	_Component->oOwner = this;
	ovComponents.push_back(_Component);
}

void Entity::SendMsg(Message* _Message)
{
	for (auto& _Component : ovComponents)
	{
		_Component->ReceiveMessage(_Message);
	}
}