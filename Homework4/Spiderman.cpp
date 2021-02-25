#include "Spiderman.h"
#include <iostream>

using namespace std;

Spiderman::Spiderman() : AnimalBasedSuperHero(), webSize(0) {}
Spiderman::Spiderman(const char *name, double age, bool radioactive, const char *animal, double webSize) : AnimalBasedSuperHero(name, age, radioactive, animal), webSize(webSize)
{
    if(webSize < 0)
        this->webSize = 0;
}
Spiderman::Spiderman(const char *animal, double webSize) : AnimalBasedSuperHero(animal), webSize(webSize)
{
    if(webSize < 0)
        this->webSize = 0;
}
Spiderman::Spiderman(double webSize) : AnimalBasedSuperHero(), webSize(webSize)
{
    if(webSize < 0)
        this->webSize = 0;
}
Spiderman::Spiderman(const Spiderman &spiderman) : AnimalBasedSuperHero(spiderman), webSize(spiderman.webSize) {}

double Spiderman::getWebSize() const
{
    return webSize;
}
void Spiderman::setWebSize(double webSize)
{
    if(webSize < 0)
        this->webSize = webSize;
}

SuperHero *Spiderman::clone() const
{
    return new Spiderman(*this);
}
ostream &Spiderman::write(ostream &out) const
{
    AnimalBasedSuperHero::write(out);
    out << "\tWeb Size: " << webSize << endl;
    return out;
}
istream &Spiderman::read(istream &in)
{
    AnimalBasedSuperHero::read(in);
    int n;
    in >> n;
    setWebSize(n);
    return in;
}

ostream &operator<<(ostream &out, const Spiderman &superHero)
{
    return superHero.write(out);
}
istream &operator>>(istream &in, Spiderman &superHero)
{
    return superHero.read(in);
}