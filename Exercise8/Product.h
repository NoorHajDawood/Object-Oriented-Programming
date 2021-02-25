#include <iostream>
#include <string>

using namespace std;

#pragma once

class Product
{
public:
    Product(const string& name, double price) : m_name(name), m_price(price) {}
    Product() : m_price(0) {}
   
public:
    virtual istream& read(istream& in);
    virtual ostream& write(ostream& out);

private:
    string	 m_name;
    double	 m_price;
};