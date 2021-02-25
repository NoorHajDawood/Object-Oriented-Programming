#include "CaptainAmerica.h"

using namespace std;

CaptainAmerica::CaptainAmerica() : ProfessionBasedSuperHero(), ageIncludingFreezing(0) {}
CaptainAmerica::CaptainAmerica(const char *name, double age, bool radioactive, const char *profession, int yearsExperience, double ageIncludingFreezing)
    : ProfessionBasedSuperHero(name, age, radioactive, profession, yearsExperience), ageIncludingFreezing(ageIncludingFreezing)
{
    if(ageIncludingFreezing < age)
        this->ageIncludingFreezing = age;
}
CaptainAmerica::CaptainAmerica(const char *profession, int yearsExperience, double ageIncludingFreezing)
: ProfessionBasedSuperHero(profession, yearsExperience), ageIncludingFreezing(ageIncludingFreezing)
{
    if(ageIncludingFreezing < age)
        this->ageIncludingFreezing = age;
}
CaptainAmerica::CaptainAmerica(double ageIncludingFreezing) : ProfessionBasedSuperHero(), ageIncludingFreezing(ageIncludingFreezing)
{
    if(ageIncludingFreezing < age)
        this->ageIncludingFreezing = age;
}
CaptainAmerica::CaptainAmerica(const CaptainAmerica &captainAmerica) : ProfessionBasedSuperHero(captainAmerica), ageIncludingFreezing(captainAmerica.ageIncludingFreezing) {}

void CaptainAmerica::setAgeIncludingFreezing(double ageIncludingFreezing)
{
    if (ageIncludingFreezing > age)
        this->ageIncludingFreezing = ageIncludingFreezing;
}

SuperHero *CaptainAmerica::clone() const
{
    return new CaptainAmerica(*this);
}
ostream &CaptainAmerica::write(ostream &out) const
{
    ProfessionBasedSuperHero::write(out);
    out << "\tAge Including Freezing: " << ageIncludingFreezing << endl;
    return out;
}
istream &CaptainAmerica::read(istream &in)
{
    ProfessionBasedSuperHero::read(in);
    int n;
    in >> n;
    setAgeIncludingFreezing(n);
    return in;
}

ostream &operator<<(ostream &out, const CaptainAmerica &superHero)
{
    return superHero.write(out);
}
istream &operator>>(istream &in, CaptainAmerica &superHero)
{
    return superHero.read(in);
}