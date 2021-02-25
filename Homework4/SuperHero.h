#pragma once
#include <iostream>

using namespace std;

class SuperHero
{
public:
	SuperHero();
	SuperHero(const char *name, double age, bool radioactive = false);
	SuperHero(const SuperHero &superHero);
	virtual ~SuperHero();

public:
	const char *getName() const { return name; }
	double getAge() const { return age; }
	bool getRadioactive() const { return radioactive; }
	void setName(const char *name);
	void setAge(double age);
	void setRadioactive(bool radioactive) { this->radioactive = radioactive; }

	virtual SuperHero *clone() const;			//
	virtual ostream &write(ostream &out) const; //
	virtual istream &read(istream &in);			//

	void setAttackMode(bool mode) { attackMode = mode; } //
	bool getAttackMode() { return attackMode; }			 //

protected:
	char *name;
	double age;
	bool radioactive;
	bool attackMode;

private:
	int nameLen; //
};

ostream &operator<<(ostream &out, const SuperHero &superHero);
istream &operator>>(istream &in, SuperHero &superHero);