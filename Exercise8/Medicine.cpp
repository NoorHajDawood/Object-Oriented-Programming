#include "Medicine.h"

/*----------------------------------------------------------------------------*/
istream& Medicine::read(istream& in)
{
	Product::read(in);
	in >> m_prescription;
    return in;
}
/*----------------------------------------------------------------------------*/
ostream& Medicine::write(ostream& out)
{
	out << "M" << endl;
	Product::write(out);
	out << m_prescription << endl;
    return out;
}