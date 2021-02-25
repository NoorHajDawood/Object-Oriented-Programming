#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Point_Null;
class Point_Size;
class String
{
protected:
    char *pstart;

public:
    String(char *p = NULL)
    {
        if (p)
        {
            pstart = new char[strlen(p) + 1];
            strcpy(pstart, p);
        }
        else
            pstart = NULL;
    }
    virtual ~String()
    {
        if (pstart)
            delete[] pstart;
    }
    virtual void print() = 0;
    virtual String *operator+(String &) = 0; //////////////////
    virtual String *operator=(String *) = 0; //////////////////
    virtual operator Point_Null() = 0;       //////////////////
    virtual operator Point_Size() = 0;       //////////////////
};

class Point_Null : public String
{
public:
    Point_Null(char *p = NULL) : String(p) {}
    void print()
    {
        cout << "point null " << pstart << endl;
    }
    String *operator+(String &other);
    String *operator=(String *other);
    operator Point_Null();
    operator Point_Size();
};
class Point_Size : public String
{
    int size;

public:
    Point_Size(char *p = NULL) : String(p)
    {
        if (p)
            size = strlen(pstart);
        else
            size = 0;
    }
    void print()
    {
        cout << "Point Size " << endl;
        for (int i = 0; i < size; i++)
            cout << pstart[i];
        cout << endl;
    }
    String *operator+(String &other);
    String *operator=(String *other);
    operator Point_Null();
    operator Point_Size();
};