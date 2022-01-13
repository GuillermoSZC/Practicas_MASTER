#pragma once

class Entity
{
public:
	Entity() { }
	virtual ~Entity() { }

	virtual void SetPosition(int _Position) = 0;
	virtual void IncreaseMovement() = 0;
	virtual void DecreaseMovement() = 0;
};

class Character : public Entity
{
private:
	int position;

public:
	Character(int _Pos) : position(_Pos) {  }

	int GetPosition() { return position; }

	virtual void SetPosition(int _Position) override;
	virtual void IncreaseMovement() override;
	virtual void DecreaseMovement() override;
};

class Bullet : public Entity
{
private:
	int position;

public:
	Bullet() : position(-1) {  }

	int GetPosition() { return position; }

	virtual void SetPosition(int _Position) override;
	virtual void IncreaseMovement() override;
	virtual void DecreaseMovement() override;
};

class Enemy : public Entity
{
private:
	int position;

public:
	Enemy() : position(-1) {  }

	int GetPosition() { return position; }

	virtual void SetPosition(int _Position) override;
	virtual void IncreaseMovement() override;
	virtual void DecreaseMovement() override;
};
