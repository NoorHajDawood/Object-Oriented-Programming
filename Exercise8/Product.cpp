#include "Product.h"

/*----------------------------------------------------------------------------*/
istream& Product::read(istream &in)
{
	in >> m_name;
	in >> m_price;
    return in;
}
/*----------------------------------------------------------------------------*/
ostream& Product::write(ostream &out)
{
	out << m_name << endl;
	out << m_price << endl;
    return out;
}