#include <iostream>
#include "Entity.h"

using namespace std;

int main()
{
	// Entity * e = new Entity();
	// e->move(1, 1);
	// cout << *e << endl;

	Player* p = new Player("Jony");
	p->move(1, 1);
	cout << *p << endl;

	Warlock* w = new Warlock();
	w->move(1, 1);
	cout << *w << endl;

	Monster* m = new Monster();
	m->move(1, 1);
	cout << *m << endl;

	SpecialPlayer* sp = new SpecialPlayer();
	sp->move(1, 1);
	cout << *sp << endl;

	Entity *eptr = new Player();
	/*Polymorphism*/
	/*Entity* e1 = p;
	cout << *e1 << endl;*/

	cin.get();
}