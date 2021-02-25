#pragma once
#include <iostream>

using namespace std;

struct Position
{
	float m_x, m_y;

	Position(float x = 0.f, float y = 0.f) : m_x(x), m_y(y) {}
	void print(ostream &out) const
	{
		out << "(" << m_x << "," << m_y << ")" << endl;
	}

	void changePos(float offX, float offY)
	{
		m_x += offX;
		m_y += offY;
	}
};
/*------------------------------------------------------------------*/
class Entity
{
public:
	Entity(){};
	~Entity(){};

public:
	virtual void move(float offX, float offY) = 0;
	void print(ostream &out) const;

protected:
	Position m_pos;
};

ostream &operator<<(ostream &out, const Entity &entity);

/*------------------------------------------------------------------*/
class Player : public Entity
{
public:
	Player() {}
	Player(const char *name) : m_name(name) {}
	~Player() {}

public:
	void move(float offX, float offY);
	void print(ostream &out) const;

protected:
	const char *m_name;
};

ostream &operator<<(ostream &out, const Player &player);
/*------------------------------------------------------------------*/
class Warlock : public Entity
{
public:
	Warlock() {}
	~Warlock() {}

public:
	void move(float offX, float offY);
	void print(ostream &out) const;

private:
};

ostream &operator<<(ostream &out, const Warlock &war);
/*------------------------------------------------------------------*/
class Monster : public Entity
{
public:
	Monster() : Entity(), m_rank(1000) {}
	~Monster() {}

public:
	void move(float offX, float offY){};
	void print(ostream &out) const;

private:
	int m_rank;
};

ostream &operator<<(ostream &out, const Monster &mon);
/*------------------------------------------------------------------*/
class SpecialPlayer : public Player
{
public:
	SpecialPlayer() : Player("Special Player"), m_weaponStrength(5) {}
	~SpecialPlayer() {}

public:
	void print(ostream &out) const;
	void attack() { cout << "Special Player in attack mode!" << endl; }

private:
	int m_weaponStrength;
};

ostream &operator<<(ostream &out, const SpecialPlayer &sp);
/*------------------------------------------------------------------*/