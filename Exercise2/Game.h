#pragma once

class Player;


class Game
{
public:
	Game();
	~Game();

public:
	void addPlayer(Player* p);
	void Print() const;

private:
	const char* m_name;
	int			m_currLevel;
	int			m_difficulty;
	int			m_numPlayers;
	Player*		m_players;
	//Player		m_p[10];

};

Game::Game()
{
	m_name = "Main Game";
	m_difficulty = 5;
	m_currLevel = 1;
	m_numPlayers = 0;
	m_players = new Player[10];
}

Game::~Game()
{
	delete[] m_players;
}

void Game::addPlayer(Player* p)
{
	if (m_numPlayers == 10)
		return;

	m_players[m_numPlayers].m_name = p->m_name;
	m_players[m_numPlayers].m_rank = p->m_rank;
	m_players[m_numPlayers].m_pos = p->m_pos;
	++m_numPlayers;
}


void Game::Print() const
{
	std::cout << "Game info..." << std::endl;
	std::cout << "Game name:" << m_name << std::endl;
	std::cout << "Game difficulty:" << m_difficulty << std::endl;
	std::cout << "Total Players: " << m_numPlayers << " printing players info" << std::endl;

	for (int i = 0; i < m_numPlayers; ++i)
	{
		std::cout << "------------------------------" << std::endl;
		m_players[i].print();
	}
}
