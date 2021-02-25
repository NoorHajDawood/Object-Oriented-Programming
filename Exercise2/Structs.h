#pragma once

#include <iostream>

struct Position
{
	int m_x, m_y;

	void Print()
	{
		std::cout << "Player position: (" << m_x << "," << m_y << ")" << std::endl;
	}

	void setPos(int x = 0, int y = 0)
	{
		m_x = x;
		m_y = y;
	}
};

struct Player
{
	const char* m_name;
	int m_rank;
	Position m_pos;

	void initPlayer(const char* name, int rank, Position pos)
	{
		m_name = name;
		m_rank = rank;
		m_pos = pos;
	}

	void print()
	{
		std::cout << "Print player info..." << std::endl;
		std::cout << "Player name:" << m_name << std::endl;
		std::cout << "Player rank:" << m_rank << std::endl;
		m_pos.Print();
	}
};
