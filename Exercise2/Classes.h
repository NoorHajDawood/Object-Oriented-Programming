#pragma once

#include <iostream>

struct Position
{
	int m_x;
	int m_y;

	void Print()
	{
		std::cout << "Player position: (" << m_x << "," << m_y << ")" << std::endl;
	}
};


class Player
{
public:
	Player(){}
	Player(const char* name, int rank, int x, int y);
	Player(Player & p){}

	~Player(){}

public:
	void print();
	

public:
	const char* m_name;
	int			m_rank;
	Position	m_pos;
};

void Player::print()
{
	std::cout << "Print player info..." << std::endl;
	std::cout << "Player name:" << m_name << std::endl;
	std::cout << "Player rank:" << m_rank << std::endl;
	m_pos.Print();
}

Player::Player(const char* name, int rank, int x, int y)
	:
	m_name(name),
	m_rank(rank)
{
	m_pos.m_x = x;
	m_pos.m_y = y;
}