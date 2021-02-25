#include <iostream>
#include "Classes.h"
#include "Game.h"

using namespace std;


int main()
{
	/*------------------------------------------------------------*/
	Player p1("Jony", 100, 0, 0);
	p1.print();

	Player* p2 = new Player("Koby", 80, 5, 8);
	p2->print();

	/*------------------------------------------------------------*/
	Game game; // Instantiation
	game.addPlayer(&p1);
	game.addPlayer(p2);
	game.Print();
	/*------------------------------------------------------------*/

	/*Do a little Clean-Up*/
	delete p2;


	cin.get();
	return 0;
}
