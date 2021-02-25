#include "ProfessionBasedSuperHero.h"
#include <cstring>

using namespace std;

ProfessionBasedSuperHero::ProfessionBasedSuperHero() : SuperHero(), profession(nullptr), professionLen(0), yearsExperience(0) {}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char *name, double age, bool radioactive, const char *profession, int yearsExperience)
 : SuperHero(name, age, radioactive), profession(nullptr), professionLen(0), yearsExperience(yearsExperience) 
{
    if(yearsExperience < 0)
        this->yearsExperience = 0;
    setProfession(profession);
}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char *profession, int yearsExperience) : SuperHero(), profession(nullptr), professionLen(0), yearsExperience(yearsExperience) 
{
    if(yearsExperience < 0)
        this->yearsExperience = 0;
    setProfession(profession);
}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const ProfessionBasedSuperHero &professionBasedSuperHero)
 : SuperHero(professionBasedSuperHero), profession(nullptr), professionLen(0), yearsExperience(professionBasedSuperHero.yearsExperience)
 {
     setProfession(professionBasedSuperHero.profession);
 }
ProfessionBasedSuperHero::~ProfessionBasedSuperHero()
{
    delete[] profession;
}

void ProfessionBasedSuperHero::setProfession(const char *profession)
{
    if (profession)
    {
        int tmpLen = strlen(profession);
        char *tmp = new char[tmpLen + 1];
        if (tmp)
        {
            strcpy(tmp, profession);
            tmp[tmpLen] = 0;
            this->profession = tmp;
            this->professionLen = tmpLen;
        }
        else
            cerr << "out of memory!" << endl;
    }
}
void ProfessionBasedSuperHero::setYearsExperience(int yearsExperience)
{
    if(yearsExperience >= 0)
        this->yearsExperience = yearsExperience;
}

SuperHero *ProfessionBasedSuperHero::clone() const
{
    return new ProfessionBasedSuperHero(*this);
}
ostream &ProfessionBasedSuperHero::write(ostream &out) const
{
    SuperHero::write(out);
    out << "\tProfession: ";
    if (profession)
        out << profession;
    out << endl << "\tYears of Experience: " << yearsExperience << endl; 
    return out;
}
istream &ProfessionBasedSuperHero::read(istream &in)
{
    SuperHero::read(in);
    string str;
    in >> str;
    setProfession(str.c_str());
    int n;
    in >> n;
    setYearsExperience(n);
    return in;
}

ostream &operator<<(ostream &out, const ProfessionBasedSuperHero &superHero)
{
    return superHero.write(out);
}
istream &operator>>(istream &in, ProfessionBasedSuperHero &superHero)
{
    return superHero.read(in);
}