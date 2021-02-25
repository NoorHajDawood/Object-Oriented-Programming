/* file: element.h */

#ifndef __ELEMENT_H
#define __ELEMENT_H
#include <iostream>
#include <string.h>
using namespace std;

class Element
{
public:
    Element(const char *key = 0, const char *dat = 0) : keystr(nullptr), data(nullptr)
    {
        if (key)
        {
            keystr = new char[strlen(key) + 1];
            strcpy(keystr, key);
        }
        if (dat)
        {
            data = new char[strlen(dat) + 1];
            strcpy(data, dat);
        }
    }
    Element(const Element &other) : keystr(nullptr), data(nullptr) { *this = other; }
    ~Element()
    {
        delete[] keystr;
        delete[] data;
    }
    Element &operator=(const Element &other)
    {
        if (this != &other)
        {
            delete[] keystr;
            if (other.keystr)
            {
                keystr = new char[strlen(other.keystr) + 1];
                strcpy(keystr, other.keystr);
            }
            else
                keystr = 0;
            delete[] data;
            if (other.data)
            {
                data = new char[strlen(other.data) + 1];
                strcpy(data, other.data);
            }
            else
                data = 0;
        }
        return *this;
    }
    bool operator==(const Element &other) const
    {
        if (!keystr && other.keystr || keystr && !other.keystr)
            return false;
        return !strcmp(keystr, other.keystr);
    }
    int Key() const
    {
        if (!keystr)
            return 0;
        return atoi(keystr);
    }
    friend ostream &operator<<(ostream &out, const Element &e);
    // You must add here public functions. See explanation above.
private:
    char *keystr;
    char *data;
};

ostream &operator<<(ostream &out, const Element &e)
{
    if (e.keystr)
        out << e.keystr << endl;
    if (e.data)
        cout << e.data << endl;
    return out;
}

#endif
