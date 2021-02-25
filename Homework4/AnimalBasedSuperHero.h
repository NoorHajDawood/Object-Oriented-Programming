#pragma once

#include "SuperHero.h"

class AnimalBasedSuperHero : public SuperHero
{
public:
	AnimalBasedSuperHero();
	AnimalBasedSuperHero(const char *name, double age, bool radioactive, const char *animal);
	AnimalBasedSuperHero(const char *animal);
	AnimalBasedSuperHero(const AnimalBasedSuperHero &animalBasedSuperHero);
	virtual ~AnimalBasedSuperHero();

public:
	void setAnimal(const char *animal);
	const char *getAnimal() const { return animal;}

	SuperHero *clone() const;			//
	ostream &write(ostream &out) const; //
	istream &read(istream &in);			//

protected:
	char *animal;
private:
	int animalLen;
};

ostream &operator<<(ostream &out, const AnimalBasedSuperHero &superHero);
istream &operator>>(istream &in, AnimalBasedSuperHero &superHero);