#pragma once
#include "Covid19.h"

class CovidSA : virtual public Covid19
{
public:
    CovidSA(float spreadCoef, int molecules, bool vaccine, const string &id, const string &source, float liver) ;//throw(invalid_argument, bad_alloc);
    ~CovidSA(){}

public:
    // Getters
    const float &getLiver() const { return mLiver; }
    // Setters
    void setLiver(float liver) ;//throw(invalid_argument);

    CovidSA *clone() const { return new CovidSA(*this); }
    ostream &print(ostream &out) const
    {
        Covid19::print(out) << "Liver Deficiency: " << mLiver << endl;
        return out;
    }

protected:
    float mLiver;
};