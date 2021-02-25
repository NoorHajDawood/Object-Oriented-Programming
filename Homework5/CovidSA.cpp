#include "CovidSA.h"

CovidSA::CovidSA(float spreadCoef, int molecules, bool vaccine, const string& id, const string& source, float liver) //throw(invalid_argument, bad_alloc)
    : Covid19(spreadCoef, molecules, vaccine, id, source), mLiver(liver)
{
    if (liver < 0 || liver > 10)
        throw invalid_argument("invalid Liver");
}

void CovidSA::setLiver(float liver) //throw(invalid_argument)
{
    if (liver < 0 || liver > 10)
        throw invalid_argument("invalid Liver");
    mLiver = liver;
}