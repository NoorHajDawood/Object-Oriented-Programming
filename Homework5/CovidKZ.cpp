#include "CovidKZ.h"

CovidKZ::CovidKZ(float spreadCoef, int molecules, bool vaccine, const string &id, const string &source, float sight, float liver, const string &mutation) //throw(invalid_argument, bad_alloc)
    : Covid19(spreadCoef, molecules, vaccine, id, source),
      CovidGB(spreadCoef, molecules, vaccine, id, source, sight),
      CovidSA(spreadCoef, molecules, vaccine, id, source, liver),
      mMutation(mutation)
{
    if (!validMutation(mMutation))
        throw invalid_argument("invalid mutation");
}

void CovidKZ::setMutation(const string &mutation) //throw(invalid_argument)
{
    if (!validMutation(mutation))
        throw invalid_argument("invalid mutation");
    mMutation = mutation;
}

bool CovidKZ::validMutation(const string &str) const
{
    if (str.length() > 20)
        return false;
    for (int i = 0; i < str.length(); i++)
    {
        if (!('A' == str[i] || 'G' == str[i] || 'T' == str[i] || 'C' == str[i] || 'a' == str[i] || 'g' == str[i] || 't' == str[i] || 'c' == str[i]))
            return false;
    }
    return true;
}