#pragma once
#include "Entity.h"

class Game
{
public:
	Game();
	~Game();

public:
	void addPlayer(const Player &p);
	void addSpecialPlayer(SpecialPlayer &sp);
	void addEntity(Entity &e);
	void addMonster(Monster &m);
	void addWarlock(Warlock &w);
	void Print() const;

private:
	const char *m_name;
	int m_currLevel;
	int m_difficulty;
	int m_numEntities;
	Entity **m_entities;
	//Player		m_p[10];
};

Game::Game()
{
	m_name = "Main Game";
	m_difficulty = 5;
	m_currLevel = 1;
	m_numEntities = 0;
	m_entities = new Entity *[10];
}

Game::~Game()
{
	delete[] m_entities;
}

void Game::addPlayer(const Player &p)
{
	if (m_numEntities == 10)
		return;
	m_entities[m_numEntities] = new Player(p);
	++m_numEntities;
}

void addSpecialPlayer(SpecialPlayer &sp)
{
	if (m_numEntities == 10)
		return;
	m_entities[m_numEntities] = new Player(p);
	++m_numEntities;
}
void addEntity(Entity &e);
void addMonster(Monster &m);
void addWarlock(Warlock &w);

void Game::Print() const
{
	std::cout << "Game info..." << std::endl;
	std::cout << "Game name:" << m_name << std::endl;
	std::cout << "Game difficulty:" << m_difficulty << std::endl;
	std::cout << "Total Players: " << m_numEntities << " printing players info" << std::endl;

	for (int i = 0; i < m_numPlayers; ++i)
	{
		std::cout << "------------------------------" << std::endl;
		m_players[i].print();
	}
}
