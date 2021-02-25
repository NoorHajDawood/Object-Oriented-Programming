#include "Avengers.h"
#include <iostream>
#include <cstring>

Avengers::Avengers(const string &teamName) : superHeros(nullptr), numSuperHeros(0), teamName(teamName) {}
Avengers::~Avengers()
{
    freeArray(superHeros, numSuperHeros);
}

void Avengers::setSuperHeros(SuperHero **superHeros, int size)
{
    if (size > 0 && !superHeros)
        cerr << "illegal call to Avengers::setSuperHeros: superHeros is nullptr" << endl;
    else if (size < 0)
        cerr << "illegal call to Avengers::setSuperHeros: size is smaller than 0" << endl;
    else
    {
        if (size == 0)
        {
            freeArray(this->superHeros, numSuperHeros);
            numSuperHeros = 0;
            return;
        }
        if (SuperHero **tmp = copyArray(superHeros, size))
        {
            freeArray(this->superHeros, numSuperHeros);
            numSuperHeros = size;
            this->superHeros = tmp;
        }
    }
}
void Avengers::addSuperHero(const SuperHero *superHero)
{
    int i;
    if (i = firstFree() != -1)
        superHeros[i] = superHero->clone();
    else
    {
        i = numSuperHeros;
        if (doubleSize())
            superHeros[i] = superHero->clone();
    }
    if(i != numSuperHeros && !(superHeros[i]))
        cerr << "out of memory!" << endl;
}
SuperHero **Avengers::getSuperHeros() const
{
    return copyArray(superHeros, numSuperHeros);
}
void Avengers::printAvengersTeam() const
{
    write(cout);
}
void Avengers::initiateTeamAttack(bool initiate)
{
    for (int i = 0; i < numSuperHeros; ++i)
    {
        if (superHeros[i])
        {
            superHeros[i]->setAttackMode(initiate);
            const char *tmp = superHeros[i]->getName();
            if (tmp)
                cout << tmp;
            //delete[] tmp;
            if (!initiate)
                cout << " not";
            cout << " in attack mode" << endl;
        }
    }
}

ostream &Avengers::write(ostream &out) const
{
    out << endl
        << "Team " << teamName << endl
        << endl;
    for (int i = 0, counter = 0; i < numSuperHeros; ++i)
    {
        if (superHeros[i])
            out << "\t----- Hero " << ++counter << " -----" << endl
                << *(superHeros[i]);
    }
    return out;
}

ostream &operator<<(ostream &out, const Avengers &team)
{
    return team.write(out);
}

void Avengers::freeArray(SuperHero **superHeros, int size)
{
    for (int i = 0; i < size; ++i)
    {
        delete superHeros[i];
    }
    delete[] superHeros;
    superHeros = 0;
}

int Avengers::firstFree() const
{
    for (int i = 0; i < numSuperHeros; i++)
        if (!superHeros[i])
            return i;
    return -1;
}

SuperHero **Avengers::copyArray(SuperHero **superHeros, int size)
{
    if (size <= 0)
        return 0;
    SuperHero **arr = new SuperHero *[size];
    if (!arr)
    {
        cerr << "out of memory!" << endl;
        return 0;
    }
    memset(arr, 0, size * sizeof(SuperHero *));
    for (int i = 0; i < size; ++i)
    {
        if (superHeros[i])
        {
            if (!(arr[i] = superHeros[i]->clone()))
            {
                cerr << "out of memory!" << endl;
                freeArray(arr, size);
                return 0;
            }
        }
    }
    return arr;
}
bool Avengers::doubleSize()
{
    SuperHero **arr = new SuperHero *[numSuperHeros * 2];
    if (!arr)
    {
        cerr << "out of memory!" << endl;
        return false;
    }
    memset(arr, 0, numSuperHeros * 2 * sizeof(SuperHero *));
    for (int i = 0; i < numSuperHeros; ++i)
        arr[i] = superHeros[i];
    delete[] superHeros;
    superHeros = arr;
    numSuperHeros *= 2;
    return true;
}