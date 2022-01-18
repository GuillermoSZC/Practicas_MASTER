#pragma once

class Entity
{
public:
	Entity() { }
	virtual ~Entity() { }

	virtual void SetPosition(int _Position) = 0;
	virtual void IncreaseMovement() = 0;
}; // INTERFACE

class Character : public Entity
{
private:
	int position;

public:
	// CONSTRUCTOR AND DESTRUCTOR
	Character(int _Pos) : position(_Pos) {  }
	~Character() { }

	int GetPosition() { return position; }
	void DecreaseMovement();

	virtual void SetPosition(int _Position) override;
	virtual void IncreaseMovement() override;
};

class Bullet : public Entity
{
private:
	int position;

public:
	// CONSTRUCTOR AND DESTRUCTOR
	Bullet(int pos) : position(pos) {  }
	~Bullet() { }

	int GetPosition() { return position; }
	void DecreaseMovement();

	virtual void SetPosition(int _Position) override;
	virtual void IncreaseMovement() override;
};

class Enemy : public Entity
{
private:
	int position;
	bool spawn;
	
public:
	// CONSTRUCTOR AND DESTRUCTOR
	Enemy(bool _Spawn, int _End);
	~Enemy() { }

	// GETTERS
	int GetPosition() { return position; }
	bool GetSpawn() { return spawn; }
	
	virtual void SetPosition(int _Position) override;
	virtual void IncreaseMovement() override;
};
