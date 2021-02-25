#include "SuperMarket.h"
#include "Food.h"
#include "Medicine.h"

/*----------------------------------------------------------------------------*/
SuperMarket::SuperMarket(const string &name,
                         const string &manager,
                         const string &address,
                         const string &closeTime,
                         const string &openTime,
                         int amount, Product **products)
    : m_name(name),
      m_manager(manager),
      m_address(address),
      m_closeTime(closeTime),
      m_openTime(openTime),
      m_amount(amount)
{
    m_products = new Product *[m_amount];
    for (int i = 0; i < m_amount; ++i)
        m_products[i] = products[i];
}
/*----------------------------------------------------------------------------*/
void SuperMarket::cleanProducts()
{
    for (int i = 0; i < m_amount; ++i)
        delete m_products[i];
    delete m_products;
}
/*----------------------------------------------------------------------------*/
SuperMarket::~SuperMarket()
{
    cleanProducts();
}
/*----------------------------------------------------------------------------*/
void SuperMarket::read(istream &in)
{
    cleanProducts();
    in >> m_name;
    in >> m_manager;
    in >> m_address;
    in >> m_closeTime;
    in >> m_openTime;
    in >> m_amount;
    m_products = new Product *[m_amount];
    for (int i = 0; i < m_amount; ++i)
    {
        m_products[i] = readProduct(in);
        if (m_products[i])
            m_products[i]->read(in);
    }
}
/*----------------------------------------------------------------------------*/
Product *SuperMarket::readProduct(istream &in)
{
    char type;
    in >> type;
    switch (type)
    {
    case 'F':
        return new Food;
    case 'M':
        return new Medicine;
    default:
        return NULL;
    }
}
/*----------------------------------------------------------------------------*/
void SuperMarket::cleanProducts()
{
    for (int i = 0; i < m_amount; ++i)
        delete m_products[i];
    delete[] m_products;
    m_products = 0;
    m_amount = 0;
}
/*----------------------------------------------------------------------------*/
void SuperMarket::write(ostream &out) const
{
    out << m_name << endl;
    out << m_manager << endl;
    out << m_address << endl;
    out << m_closeTime << endl;
    out << m_openTime << endl;
    out << m_amount << endl;
    for (int i = 0; i < m_amount; ++i)
        if (m_products[i])
            m_products[i]->write(out);
}
/*----------------------------------------------------------------------------*/
istream &operator>>(istream &in, SuperMarket &superMarket)
{
    superMarket.read(in);
    return in;
}
/*----------------------------------------------------------------------------*/
ostream &operator<<(ostream &out, const SuperMarket &superMarket)
{
    superMarket.write(out);
    return out;
}
/*----------------------------------------------------------------------------*/