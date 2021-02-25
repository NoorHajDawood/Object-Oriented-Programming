#pragma once

#include "Product.h"

class SuperMarket
{
public:
    SuperMarket(const string &name,
                const string &manager,
                const string &address,
                const string &closeTime,
                const string &openTime,
                int numOfProducts, Product **products);

    SuperMarket() : m_amount(0), m_products(NULL) {}
    ~SuperMarket();

public:
    void read(istream &in);
    void write(ostream &out) const;

private:
    Product *readProduct(istream &in);
    void cleanProducts();

private:
    string m_name;
    string m_manager;
    string m_address;
    string m_closeTime;
    string m_openTime;
    int m_amount;
    Product **m_products;
};

istream &operator>>(istream &in, SuperMarket &superMarket);
ostream &operator<<(ostream &out, const SuperMarket &superMarket);