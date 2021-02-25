#include <iostream>
#include "shapes.h"


using namespace std;

int main()
{
	Circle* c = new Circle();
	c->draw();

	Triangle* t = new Triangle();
	t->draw();

	Square* s = new Square();
	s->draw();

	Shape* shape = new Circle();
	shape->draw();

	cout << "enter a symbol" << endl;
	char ch;
	cin >> ch;

	switch (ch)
	{
	case 'c':
		shape = new Circle();
		break;
	case 's':
		shape = new Square();
		break;
	case 't':
		shape = new Triangle();
		break;
	default:
		break;
	}


	shape->draw();
	Circle * circle = dynamic_cast<Circle*>(shape);
	if (nullptr != circle)
		circle->print();


}