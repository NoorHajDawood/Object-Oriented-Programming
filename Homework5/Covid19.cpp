#include "Covid19.h"

Covid19::Covid19(float spreadCoef, int molecules, bool vaccine, const string& id, const string& source) //throw(invalid_argument, bad_alloc)
    : mSpreadCoef(spreadCoef), mMolecules(molecules), mVaccine(vaccine), cID(id), mSource(source)
{
    if (!validID(cID))
        throw invalid_argument("invalid ID");
    if (spreadCoef < 0)
        throw invalid_argument("invalid spread coefficent");
    if (molecules < 0)
        throw invalid_argument("invalid molecules count");
}

void Covid19::setSpreadCoef(float spreadCoef) //throw(invalid_argument)
{
    if (spreadCoef < 0)
        throw invalid_argument("invalid spread coefficent");
    mSpreadCoef = spreadCoef;
}
void Covid19::setMolecules(int molecules) //throw(invalid_argument)
{
    if (molecules < 0)
        throw invalid_argument("invalid molecules count");
    mMolecules = molecules;
}
void Covid19::setVaccine(bool vaccine)
{
    mVaccine = vaccine;
}
void Covid19::setSource(const string& source)
{
    mSource = source;
}

bool Covid19::validID(const string& str) const
{
    if (str.length() != 20)
        return false;
    for (int i = 0; i < 20; i++)
    {
        if (!(('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')))
            return false;
    }
    return true;
}

ostream& operator<<(ostream &out, const Covid19& virus)
{
    virus.print(out);
    return out;
}