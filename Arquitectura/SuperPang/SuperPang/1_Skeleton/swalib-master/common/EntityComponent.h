#pragma once
#include <iostream>
#include <vector>
#include "MessageManager.h"

class Entity;
class Message;

class Component
{
protected: 
	Entity* oOwner;

private:
	friend class Entity;

public:
	Component(); 
	virtual ~Component() { }

	virtual void Slot(float _Elapsed) = 0;
	virtual void ReceiveMessage(Message* _Message) = 0;

};

class Entity
{
protected:
	const char* name;
	bool activated;

private:
	std::vector<Component*> ovComponents;
	size_t idEntity;

public:
	Entity() : activated(true), name("entity"), idEntity(0) { }
	~Entity();

	// SETTERS
	void SetID(size_t _ID) { idEntity = _ID; }
	void Activated(bool _Active) { activated = _Active; }
	void SetName(const char* _Name) { name = _Name; }
	void SetActive(bool _Activated) { activated = _Activated; }

	// GETTERS
	size_t GetID() { return idEntity; }
	const char* GetName() { return name; }
	bool GetActive() { return activated; }

	// FUNCTIONS
	void Slot(float _Elapsed);
	void AddComponent(Component* _Component);
	void SendMsg(Message* _Message);

	template<typename T>
	T* FindComponent()
	{
		for (auto& i : ovComponents)
		{
			T* component = dynamic_cast<T*>(i);
			if (component)
				return component;
		}
		return NULL;
	}
};