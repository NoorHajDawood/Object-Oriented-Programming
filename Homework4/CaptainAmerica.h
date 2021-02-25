#pragma once

#include "ProfessionBasedSuperHero.h"
#include "SuperHero.h"

class CaptainAmerica : public ProfessionBasedSuperHero
{
public:
	CaptainAmerica();
	CaptainAmerica(const char *name, double age, bool radioactive, const char *profession, int yearsExperience, double ageIncludingFreezing);
	CaptainAmerica(const char *profession, int yearsExperience, double ageIncludingFreezing);
	CaptainAmerica(double ageIncludingFreezing);
	CaptainAmerica(const CaptainAmerica &captainAmerica);
	virtual ~CaptainAmerica(){}

public:
	double getAgeIncludingFreezing() const { return ageIncludingFreezing; }
	void setAgeIncludingFreezing(double ageIncludingFreezing);

	SuperHero *clone() const;			//
	ostream &write(ostream &out) const; //
	istream &read(istream &in);			//

protected:
	double ageIncludingFreezing;
};

ostream &operator<<(ostream &out, const CaptainAmerica &superHero);
istream &operator>>(istream &in, CaptainAmerica &superHero);