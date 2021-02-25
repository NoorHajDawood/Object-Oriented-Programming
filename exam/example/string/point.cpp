#include "point.h"

///////// STRING
String *String::operator=(String *other)
{
    if (this != other)
    {
        delete[] this->pstart;
        this->pstart = 0;
        if (other->pstart != 0)
        {
            this->pstart = new char[strlen(other->pstart) + 1];
            strcpy(this->pstart, other->pstart);
        }
    }
    return this;
}
String *String::operator+(String &other)
{
    char *cat = new char[strlen(pstart) + strlen(other.pstart) + 1];
    strcpy(cat, pstart);
    strcat(cat, other.pstart);
    return new Point_Null(cat);
}

////////// Point_Null
String *Point_Null::operator+(String &other)
{
    return String::operator+(other);
}
String *Point_Null::operator=(String *other)
{
    return String::operator=(other);
}
Point_Null::operator Point_Null()
{
    return *this;
}
Point_Null::operator Point_Size()
{
    return Point_Size(pstart);
}


////////// Point_Size
String *Point_Size::operator+(String &other)
{
    return String::operator+(other);
}
String *Point_Size::operator=(String *other)
{
    String::operator=(other);
    size = strlen(pstart);
    return this;
}
Point_Size::operator Point_Null()
{
    return Point_Null(pstart);
}
Point_Size::operator Point_Size()
{
    return *this;
}