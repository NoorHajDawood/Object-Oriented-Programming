#include "SuperHero.h"
#include <cstring>
#include <iostream>

using namespace std;

SuperHero::SuperHero() : name(nullptr), nameLen(0), age(0), radioactive(false), attackMode(false) {}
SuperHero::SuperHero(const char *name, double age, bool radioactive) : name(nullptr), nameLen(0), age(age), radioactive(radioactive), attackMode(false)
{
    if (!(15 <= age && age <= 40))
        this->age = 0;
    if (name)
        setName(name);
}
SuperHero::SuperHero(const SuperHero &superHero) : name(nullptr), nameLen(0), age(superHero.age), radioactive(superHero.radioactive), attackMode(superHero.attackMode)
{
    setName(superHero.name);
}
SuperHero::~SuperHero()
{
    delete[] name;
}
// const char *SuperHero::getName() const
// {
//     char *tmp = new char[nameLen + 1];
//     if (tmp)
//     {
//         strcpy(tmp, name);
//         tmp[nameLen] = 0;
//     }
//     else
//         cerr << "out of memory!" << endl;
//     return tmp;
// }
void SuperHero::setName(const char *name)
{
    if (name)
    {
        int tmpLen = strlen(name);
        char *tmp = new char[tmpLen + 1];
        if (tmp)
        {
            strcpy(tmp, name);
            tmp[tmpLen] = 0;
            delete[] this->name;
            this->name = tmp;
        }
        else
            cerr << "out of memory!" << endl;
    }
}
void SuperHero::setAge(double age)
{
    if (15 <= age && age <= 40)
        this->age = age;
}
SuperHero *SuperHero::clone() const
{
    return new SuperHero(*this);
}
ostream &SuperHero::write(ostream &out) const
{
    out << "\tName: ";
    if (name)
        out << name;
    cout << endl
         << "\tAge: " << age << endl
         << "\tRadioactive: " << (radioactive ? "Yes" : "No") << endl
         << "\tAttack Mode: " << (attackMode ? "Active" : "Disabled") << endl;
    return out;
}
istream &SuperHero::read(istream &in)
{
    string str;
    in >> str;
    setName(str.c_str());
    int age;
    in >> age;
    setAge(age);
    bool tmpBool;
    in >> tmpBool;
    setRadioactive(tmpBool);
    in >> tmpBool;
    setAttackMode(tmpBool);
    return in;
}

ostream &operator<<(ostream &out, const SuperHero &superHero)
{
    return superHero.write(out);
}
istream &operator>>(istream &in, SuperHero &superHero)
{
    return superHero.read(in);
}