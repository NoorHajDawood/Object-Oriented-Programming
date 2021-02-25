#pragma once

#include "SuperHero.h"
#include "Spiderman.h"
#include "AnimalBasedSuperHero.h"
#include "ProfessionBasedSuperHero.h"
#include "CaptainAmerica.h"
#include <string>

using namespace std;

class Avengers
{
public:
	Avengers(const string &teamName);
	~Avengers();

public:
	void setSuperHeros(SuperHero **superHeros, int size);
	void addSuperHero(const SuperHero *superHero);
	SuperHero **getSuperHeros() const;
	void printAvengersTeam() const;
	void initiateTeamAttack(bool initiate);

	ostream &write(ostream &out) const; //
	//istream &read(istream &in); //

private:
	static void freeArray(SuperHero **superHeros, int size);		//
	int firstFree() const;											//
	static SuperHero **copyArray(SuperHero **superHeros, int size); //
	bool doubleSize();												//

private:
	SuperHero **superHeros;
	int numSuperHeros;
	string teamName;
};

ostream &operator<<(ostream &out, const Avengers &superHero);
//istream &operator>>(istream &in, const Avengers &superHero);