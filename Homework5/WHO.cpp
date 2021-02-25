#include "WHO.h"
#include <string.h>
WHO::WHO(Covid19 **arr, int size, const string &country, int population, int sickCount)
    : pArray(nullptr), mArraySize(size), mArrayCurrent(0), mCountry(country), mPopulation(population), mSickCount(sickCount)
{
    if (arr)
        copyArray(arr);
    else
        initialize();
}
WHO::WHO(const WHO &other)
    : pArray(nullptr), mArraySize(other.mArraySize), mArrayCurrent(0), mCountry(other.mCountry), mPopulation(other.mPopulation), mSickCount(other.mSickCount)
{
    if (other.pArray)
        copyArray(other.pArray);
    else
        initialize();
}
WHO::~WHO()
{
    emptyArray();
    delete[] pArray;
}
void WHO::initialize()
{
    if(pArray)
    {
        emptyArray();
        delete[] pArray;
    }
    mArraySize = 5;
    mArrayCurrent = 0;
    pArray = new Covid19 *[5];
    memset(pArray, 0, 5 * sizeof(Covid19 *));
}
WHO &WHO::operator=(const WHO &other) //throw(bad_alloc)
{
    if (this != &other)
    {
        Covid19 **tmpArray = pArray;
        int tmpSize = mArraySize, tmpCurrent = mArrayCurrent;

        mArraySize = other.mArraySize;
        mArrayCurrent = 0;
        if (other.pArray)
            copyArray(other.pArray);
        else
        {
            emptyArray();
            delete[] pArray;
            pArray = nullptr;
        }
        if (other.pArray == nullptr || pArray != tmpArray)
        {
            mCountry = other.mCountry;
            mPopulation = other.mPopulation;
            mSickCount = other.mSickCount;
        }
        else
        {
            mArraySize = tmpSize;
            mArrayCurrent = tmpCurrent;
            //throw bad_alloc();
        }
    }
    return *this;
}
void WHO::addVirus(const Covid19 &virus)
{
    if(mArraySize == 0)
        initialize();
    if (mArrayCurrent == mArraySize)
    {
        int tmpSize = mArraySize;
        doubleArray();
        if (mArraySize == tmpSize)
            return;
    }
    if (findID(virus.getID()) != -1)
        return; //throw "already exists";
    int i = firstFree();
    try
    {
        pArray[i] = virus.clone();
        ++mArrayCurrent;
    }
    catch (bad_alloc)
    {
        cerr << "Out of Memory" << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << endl;
    }
}
void WHO::changeMutation(const string &id, const string &mutation) //throw(const char *, invalid_argument) //"Unable to change genetic code CovidGB does not support!"
{
    int i = findID(id);
    if (i == -1)
    {
        cerr << "Unable to change genetic code, ID doesn't exist" << endl;
        throw "Unable to change genetic code, ID doesn't exist";
    }
    CovidKZ *kz = dynamic_cast<CovidKZ *>(pArray[i]);
    if (!kz)
    {
        err = "Unable to change genetic code ";
        (err += typeid(*pArray[i]).name()) += " does not support!";
        cerr << err << endl;
        throw err.c_str();
    }
    kz->setMutation(mutation);
}
void WHO::setPopulation(int population)
{
    if (population >= 0)
    {
        mPopulation = population;
        if (mSickCount > population)
            mSickCount = population;
    }
}
void WHO::setSickCount(int sickCount)
{
    if (sickCount > 0 && sickCount <= mPopulation)
        mSickCount = sickCount;
}
void WHO::setArray(Covid19 **arr, int size)
{
    Covid19 **tmpArray = pArray;
    int tmpSize = mArraySize, tmpCurrent = mArrayCurrent;

    mArraySize = size;
    mArrayCurrent = 0;
    if (arr)
        copyArray(arr);
    else
    {
        emptyArray();
        delete[] pArray;
        pArray = nullptr;
    }
    if (!(arr == nullptr || pArray != tmpArray))
    {
        mArraySize = tmpSize;
        mArrayCurrent = tmpCurrent;
        throw bad_alloc();
    }
}
void WHO::copyArray(Covid19 **arr)
{
    Covid19 **tmp = nullptr;
    try
    {
        tmp = new Covid19 *[mArraySize];
        for (int i = 0; i < mArraySize; ++i)
        {
            if (arr[i])
            {
                tmp[i] = arr[i]->clone();
                ++mArrayCurrent;
            }
            else
                tmp[i] = nullptr;
        }
        emptyArray();
        delete[] pArray;
        pArray = tmp;
    }
    catch (bad_alloc)
    {
        for (int i = 0, j = 0; i < mArraySize && j < mArrayCurrent; ++i)
        {
            if (tmp[i])
            {
                ++j;
                delete tmp[i];
            }
        }
        delete[] tmp;
        mArrayCurrent = 0;
        mArraySize = 0;
        cerr << "Out of Memory" << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << endl;
    }
}
void WHO::doubleArray()
{
    Covid19 **tmp = nullptr;
    try
    {
        tmp = new Covid19 *[mArraySize * 2];
        int i;
        for (i = 0; i < mArraySize; ++i)
            tmp[i] = pArray[i];
        for (; i < (mArraySize * 2); ++i)
            tmp[i] = nullptr;
        delete[] pArray;
        pArray = tmp;
        mArraySize *= 2;
    }
    catch (bad_alloc)
    {
        delete[] tmp;
        cerr << "Out of Memory" << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << endl;
    }
}
void WHO::emptyArray()
{
    if (pArray)
    {
        for (int i = 0; i < mArraySize; ++i)
        {
            delete pArray[i];
            pArray[i] = nullptr;
        }
    }
}
int WHO::firstFree() const
{
    for (int i = 0; i < mArraySize; ++i)
        if (!pArray[i])
            return i;
    return -1;
}
int WHO::findID(const string &id) const
{
    for (int i = 0; i < mArraySize; ++i)
        if (pArray[i])
            if (pArray[i]->getID() == id)
                return i;
    return -1;
}
ostream &WHO::print(ostream &out) const
{
    out << "--------- WHO ---------" << endl;
    out << "Country: " << mCountry << endl
        << "Population: " << mPopulation << endl
        << "Sick People: " << mSickCount << endl;
    out << "List of virus:" << endl;
    for (int i = 0; i < mArraySize; ++i)
    {
        if (pArray[i])
        {
            out << "----- " << typeid(*pArray[i]).name() << " -----" << endl;
            out << *pArray[i];
        }
    }

    return out;
}
void WHO::print() const
{
    print(cout);
}