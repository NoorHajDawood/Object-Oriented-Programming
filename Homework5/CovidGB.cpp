#include "CovidGB.h"

CovidGB::CovidGB(float spreadCoef, int molecules, bool vaccine, const string& id, const string& source, float sight) //throw(invalid_argument, bad_alloc)
    : Covid19(spreadCoef, molecules, vaccine, id, source), mSight(sight)
{
    if (sight < 0 || sight > 10)
        throw invalid_argument("invalid Sight");
}

void CovidGB::setSight(float sight) //throw(invalid_argument)
{
    if (sight < 0 || sight > 10)
        throw invalid_argument("invalid Sight");
    mSpreadCoef = sight;
}