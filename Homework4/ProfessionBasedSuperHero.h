#pragma once

#include "SuperHero.h"
#include <iostream>

class ProfessionBasedSuperHero : public SuperHero
{
public:
	ProfessionBasedSuperHero();
	ProfessionBasedSuperHero(const char *name, double age, bool radioactive, const char *profession, int yearsExperience);
	ProfessionBasedSuperHero(const char *profession, int yearsExperience);
	ProfessionBasedSuperHero(const ProfessionBasedSuperHero &professionBasedSuperHero);
	virtual ~ProfessionBasedSuperHero();

public:
	void setProfession(const char *profession);
	const char *getProfession() const { return profession; }
	void setYearsExperience(int yearsExperience);
	int getYearsExperience() const { return yearsExperience; }

	SuperHero *clone() const;			//
	ostream &write(ostream &out) const; //
	istream &read(istream &in);			//

protected:
	int yearsExperience;
	char *profession;

private:
	int professionLen;
};

ostream &operator<<(ostream &out, const ProfessionBasedSuperHero &superHero);
istream &operator>>(istream &in, ProfessionBasedSuperHero &superHero);