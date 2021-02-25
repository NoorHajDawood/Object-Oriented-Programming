#include "String.h"
#include <string.h>

#define LEN 200

/*-------------------------------------------------------------------------------*/
String::String(const char* str)
{
	_len = strlen(str) + 1;
	_p = new char[_len];
	strncpy(_p, str, _len - 1);
	_p[_len - 1] = '\0';
}
/*-------------------------------------------------------------------------------*/
// Copy constructor
String::String(const String& str) : _p(NULL), _len(0)
{
	*this = str; // Calls the assignment operator on this
}
/*-------------------------------------------------------------------------------*/
// Assignment of a String object (str) to this
String& String::operator = (const String& str)
{
	if (this != &str)
	{
		delete[] _p;
		_len = str._len;
		_p = new char[_len];
		strncpy(_p, str._p, _len);
	}
	return *this;
}
/*-------------------------------------------------------------------------------*/
// Appending a given object (str) to this
String& String::operator += (const String& str)
{
	char* newStr = new char[_len + str._len - 1];
	strncpy(newStr, _p, _len);
	strncat(newStr, str._p, str._len);
	delete[] _p;
	_len = _len + str._len - 1;
	_p = newStr;
	return *this;
}
/*-------------------------------------------------------------------------------*/
// Compares the given String object (str) with this
bool String::operator == (const String& str) const
{
	return strcmp(_p, str._p) == 0;
}
/*-------------------------------------------------------------------------------*/
String String::operator + (const String& str) const
{
    String result = *this;
    result += str; // Calls the += operator on result
    return result;
}
/*-------------------------------------------------------------------------------*/
// returns the object at index (index) for a constant object
const char& String::operator[] (int index) const
{
    if (index >= 0 && index < _len)
        return _p[index];

    cout << "Invalid index" << endl;
	return '\0';
}
/*-------------------------------------------------------------------------------*/
bool String::operator != (const String& str) const
{
    return strcmp(_p, str._p) != 0;
}
/*-------------------------------------------------------------------------------*/
bool String::operator > (const String& str) const
{
    return strcmp(_p, str._p) > 0;
}
/*-------------------------------------------------------------------------------*/
bool String::operator < (const String& str) const
{
    return strcmp(_p, str._p) < 0; //*this != str && !(*this > str);
}
/*-------------------------------------------------------------------------------*/
bool String::operator >= (const String& str) const
{
    return strcmp(_p, str._p) >= 0;//!(*this < str);
}
/*-------------------------------------------------------------------------------*/
bool String::operator <= (const String& str) const
{
    return strcmp(_p, str._p) <= 0;//!(*this > str);
}
/*-------------------------------------------------------------------------------*/
istream& operator >> (istream &in, String &str)
{
	char tmp[LEN];
	in >> tmp;
	str = String(tmp);
	return in;
}
/*-------------------------------------------------------------------------------*/
ostream& operator << (ostream& out, const String& str)
{
	return (out << str._p);
}
/*-------------------------------------------------------------------------------*/