#include "Avengers.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	SuperHero *superArr[5];
	superArr[0] = new SuperHero("Clark Kent", 25);
	superArr[1] = new ProfessionBasedSuperHero("IronMan", 38, false, "entrepreneur", 18);
	superArr[2] = new AnimalBasedSuperHero("Scott Lang", 30, false, "Ant");
	superArr[3] = new CaptainAmerica("Steve Rogers", 22, true, "soldier", 75, 89);
	superArr[4] = new Spiderman("Peter Parker", 17, true, "spider", 2.3);
	
	Avengers team("Avengers");
	team.setSuperHeros(superArr, 5);
	cout << team << endl;
	team.addSuperHero(new AnimalBasedSuperHero("Batman", 35, false, "Bat"));
	team.initiateTeamAttack(true);
	team.printAvengersTeam();
	cout << team << endl;
	
	for(int i = 0; i < 5; ++i)
		delete superArr[i];
	/*3 pts Bonus - Write and read the avengers team from file*/


	return 0;
}
