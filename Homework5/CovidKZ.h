#pragma once
#include "CovidGB.h"
#include "CovidSA.h"

class CovidKZ : public CovidGB, public CovidSA
{
public:
    CovidKZ(float spreadCoef, int molecules, bool vaccine, const string &id, const string &source, float sight, float liver, const string &mutation) ;//throw(invalid_argument, bad_alloc);
    ~CovidKZ() {}

public:
    // Getters
    const string &getMutation() const { return mMutation; }
    // Setters
    void setMutation(const string &mutation) ;//throw(invalid_argument);

    CovidKZ *clone() const { return new CovidKZ(*this); }
    ostream &print(ostream &out) const
    {
        Covid19::print(out) << "Sight Deficiency: " << mSight << endl
                            << "Liver Deficiency: " << mLiver << endl
                            << "Mutation: " << mMutation << endl;
        return out;
    }

protected:
    string mMutation;

private:
    bool validMutation(const string &str) const;
};