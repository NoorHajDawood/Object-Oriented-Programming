#pragma once

#include "Product.h"

class Medicine : public Product
{
public:
	Medicine(const string& name, double price, bool prescription = false) : Product(name, price), m_prescription(prescription) {}
    Medicine() : m_prescription(false) {}

public:
    virtual istream& read(istream& in);
    virtual ostream& write(ostream& out);

private:
    bool m_prescription;
};