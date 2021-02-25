#pragma once
#include "CovidKZ.h"

class WHO
{
public:
    WHO();
    WHO(Covid19 **array = nullptr, int size = 0, const string& country = "", int population = 0, int sickCount = 0);
    WHO(const WHO& other);
    ~WHO();

public:
    WHO& operator=(const WHO& other); //throw(bad_alloc);
    void addVirus(const Covid19& virus); //throw(const char*)
    void changeMutation(const string& id, const string& mutation) ;//throw(const char*, invalid_argument); //"Unable to change genetic code CovidGB does not support!"

    // Getters
    const string& getCountry() const { return mCountry; }
    const int& getPopulation() const { return mPopulation; }
    const int& getSickCount() const { return mSickCount; }
    // Setters
    void setCountry(const string& country) { mCountry = country; } 
    void setPopulation(int population);
    void setSickCount(int sickCount);
    void setArray(Covid19 **arr, int size);
    void emptyArray();

    ostream& print(ostream& out) const;
    void print() const;
private:
    void copyArray( Covid19 **arr);
    void doubleArray();
    int firstFree() const;
    int findID(const string& id) const;
    void initialize();
private:
    Covid19 **pArray;
    int mArraySize;
    int mArrayCurrent;
    string mCountry;
    int mPopulation;
    int mSickCount;
    string err;
};