#include "AnimalBasedSuperHero.h"
#include <cstring>
#include <iostream>

using namespace std;

AnimalBasedSuperHero::AnimalBasedSuperHero() : SuperHero(), animal(nullptr), animalLen(0) {}
AnimalBasedSuperHero::AnimalBasedSuperHero(const char *name, double age, bool radioactive, const char *animal) : SuperHero(name, age, radioactive), animal(nullptr), animalLen(0)
{
    setAnimal(animal);
}
AnimalBasedSuperHero::AnimalBasedSuperHero(const char *animal) : SuperHero(), animal(nullptr), animalLen(0)
{
    setAnimal(animal);
}
AnimalBasedSuperHero::AnimalBasedSuperHero(const AnimalBasedSuperHero &animalBasedSuperHero) : SuperHero(animalBasedSuperHero), animal(nullptr), animalLen(0)
{
    setAnimal(animalBasedSuperHero.animal);
}
AnimalBasedSuperHero::~AnimalBasedSuperHero()
{
    delete[] animal;
}

void AnimalBasedSuperHero::setAnimal(const char *animal)
{
    if (animal)
    {
        int tmpLen = strlen(animal);
        char *tmp = new char[tmpLen + 1];
        if (tmp)
        {
            strcpy(tmp, animal);
            tmp[tmpLen] = 0;
            this->animal = tmp;
            this->animalLen = tmpLen;
        }
        else
            cerr << "out of memory!" << endl;
    }
}
// const char *AnimalBasedSuperHero::getAnimal() const
// {
//     char *tmp = new char[animalLen + 1];
//     if (tmp)
//     {
//         strcpy(tmp, animal);
//         tmp[animalLen] = 0;
//     }
//     else
//         cerr << "out of memory!" << endl;
//     return tmp;
// }
SuperHero *AnimalBasedSuperHero::clone() const
{
    return new AnimalBasedSuperHero(*this);
}
ostream &AnimalBasedSuperHero::write(ostream &out) const
{
    SuperHero::write(out);
    out << "\tAnimal: ";
    if(animal)
        out << animal;
    return out << endl;
}
istream &AnimalBasedSuperHero::read(istream &in)
{
    SuperHero::read(in);
    string str;
    in >> str;
    setAnimal(str.c_str());
    return in;
}

ostream &operator<<(ostream &out, const AnimalBasedSuperHero &superHero)
{
    return superHero.write(out);
}
istream &operator>>(istream &in, AnimalBasedSuperHero &superHero)
{
    return superHero.read(in);
}