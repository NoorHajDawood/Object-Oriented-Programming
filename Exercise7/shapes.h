#pragma once
#include <iostream>
using namespace std;

/**********************************************************************************/
class Shape
{
public:
	Shape(){}
	~Shape(){}


public:
	virtual void draw() { cout << "_____drawing Shape______" << endl;}


public:
	int m_scale = 1;
};
/**********************************************************************************/
class Circle : public Shape
{
public:
	Circle(){}
	~Circle(){}

public:
	virtual void draw() { cout << "_____drawing Circle______" << endl;}
	void print() { cout << "I'm circle" << endl; }

public:
	int m_radius = 2;
};
/**********************************************************************************/
class Triangle : public Shape
{
public:
	Triangle() {}
	~Triangle() {}

public:
	virtual void draw() { cout << "_____drawing Triangle______" << endl; }

protected:
	int m_height = 5;
};
/**********************************************************************************/
class Square : public Shape
{
public:
	Square() {}
	~Square() {}

public:
	virtual void draw() { cout << "_____drawing Square______" << endl;}

protected:
	float m_edge = 7.5f;
};

