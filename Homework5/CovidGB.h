#pragma once
#include "Covid19.h"

class CovidGB : virtual public Covid19
{
public:
    CovidGB(float spreadCoef, int molecules, bool vaccine, const string &id, const string &source, float sight) ;//throw(invalid_argument, bad_alloc);
    ~CovidGB(){}

public:
    // Getters
    const float &getSight() const { return mSight; }
    // Setters
    void setSight(float sight) ;//throw(invalid_argument);

    CovidGB *clone() const { return new CovidGB(*this); }
    ostream &print(ostream &out) const
    {
        Covid19::print(out) << "Sight Deficiency: " << mSight << endl;
        return out;
    }

protected:
    float mSight;
};