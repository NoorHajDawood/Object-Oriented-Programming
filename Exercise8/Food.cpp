#include "Food.h"


/*----------------------------------------------------------------------------*/
istream& Food::read(istream& in)
{
	Product::read(in);
	in >> m_calories;
    return in;
}
/*----------------------------------------------------------------------------*/
ostream& Food::write(ostream& out)
{
	out << "F" << endl;
	Product::write(out);
	out << m_calories << endl;
    return out;
}