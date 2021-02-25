#pragma once
#include <iostream>
#include <string>

using namespace std;

class Covid19
{
public:
    Covid19(float spreadCoef, int molecules, bool vaccine, const string &id, const string &source) ;//throw(invalid_argument, bad_alloc);
    virtual ~Covid19(){}

public:
    // Getters
    const float &getSpreadCoef() const { return mSpreadCoef; }
    const int &getMolecules() const { return mMolecules; }
    const bool &getVaccine() const { return mVaccine; }
    const string &getID() const { return cID; }
    const string &getSource() const { return mSource; }
    //Setters
    void setSpreadCoef(float spreadCoef) ;//throw(invalid_argument);
    void setMolecules(int molecules) ;//throw(invalid_argument);
    void setVaccine(bool vaccine);
    void setSource(const string &source);

    virtual Covid19 *clone() const { return new Covid19(*this); }
    virtual ostream &print(ostream &out) const
    {
        out << "Covid ID: " << cID << endl
            << "Spread Coefficient: " << mSpreadCoef << endl
            << "Molecules: " << mMolecules << endl
            << "Vaccine availability: " << mVaccine << endl
            << "Source: " << mSource << endl;
        return out;
    }

protected:
    float mSpreadCoef;
    int mMolecules;
    bool mVaccine;
    const string cID;
    string mSource;

private:
    bool validID(const string &str) const;
};

ostream& operator<<(ostream &out, const Covid19& virus);