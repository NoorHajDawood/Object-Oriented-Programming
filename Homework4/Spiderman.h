#pragma once

#include "AnimalBasedSuperHero.h"
#include "SuperHero.h"

class Spiderman : public AnimalBasedSuperHero
{
public:
	Spiderman();
	Spiderman(const char *name, double age, bool radioactive, const char *animal, double webSize);
	Spiderman(const char *animal, double webSize);
	Spiderman(double webSize);
	Spiderman(const Spiderman &spiderman);
	virtual ~Spiderman(){}

	double getWebSize() const;
	void setWebSize(double webSize);

	SuperHero *clone() const;			//
	ostream &write(ostream &out) const; //
	istream &read(istream &in);			//

protected:
	double webSize;
};

ostream &operator<<(ostream &out, const Spiderman &superHero);
istream &operator>>(istream &in, Spiderman &superHero);