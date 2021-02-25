#include "Palindrome.h"
#include <iostream>
/* constructor / default constructor (has default value) */
Palindrome::Palindrome(const std::string &other) : half(), size(0)
{
    if (other.compare("") && isPalindrome(other)) // not empty or not a palindrome then skip
    {
        size = other.length();
        half = other.substr(0, size / 2 + size % 2); //abba // aba
    }
}
/* copy constructor - calls the copy constructor of string */
Palindrome::Palindrome(const Palindrome &other) : half(other.half), size(other.size) {}

/* delete - string::~string is called */
Palindrome::~Palindrome() {}

Palindrome &Palindrome::operator=(const Palindrome &other)
{
    if (this != &other) // self check
    {
        half = other.half;
        size = other.size;
    }
    return *this;
}
Palindrome &Palindrome::operator+=(const Palindrome &other)
{
    if (other.size != 0) // check if there's no need to add
    {
        half += other.half;
        size = size + size % 2 + other.size;
    }
    return *this;
}
Palindrome &Palindrome::operator+=(char c)
{
    half.insert(0, 1, c); // add c to the start of the half palindrome
    size += 2;            // size is larger by 2 characters
    return *this;
}
Palindrome &Palindrome::operator-=(const Palindrome &other)
{
    int index;
    if (other.size != 0 && other.size <= size && !(size % 2 == 0 && other.size % 2 != 0) && ((index = half.find(other.half)) >= 0)) // other doesn't exist in this
    {
        if (other.size % 2) // other's size is odd, there for other has to be in the middle
            index = half.length() - other.half.length();
        else if (size % 2 && index == (half.length() - other.half.length()))    // this's size is odd and other is not but it appears in the middle, then illegal
            return *this;
        std::string tmp = half;
        if (other.size%2 && half.compare(index, other.half.length(), other.half) != 0)  // if other was odd but he didn't apear in the middle then illegal
            return *this;
        half.erase(index, other.half.length());
        if (tmp.compare(half))
            size = size - other.size;
    }
    return *this;
}
Palindrome Palindrome::operator+(const Palindrome &other) const
{
    return Palindrome(*this) += other; // call += with a new palindrome
}
Palindrome Palindrome::operator++(int)
{
    Palindrome p(*this); // hold old palindrome then increase
    ++(half[0]);
    if (half[0] == ('9' + 1))
        half[0] = '0';
    if (half[0] == ('z' + 1))
        half[0] = 'a';
    if (half[0] == ('Z' + 1))
        half[0] = 'A';
    return p;
}
bool Palindrome::operator==(const Palindrome &other) const
{
    if (size != other.size) // if size is not equal
        return false;
    return toLower(half).compare(toLower(other.half)) == 0; // other wise check with lower_case
}
std::string Palindrome::toLower(std::string lower) // convert string to lower_case string
{
    for (int i = 0; i < lower.length(); i++)
    {
        if ('A' <= lower[i] && lower[i] <= 'Z')
            lower[i] += 'a' - 'A';
    }
    return lower;
}
Palindrome Palindrome::operator!() const
{
    return toLower((const char *)*this); // make a new palindrome with lower_case this
}
char Palindrome::operator[](int i) const
{
    if (i < 0 || i >= size) // check if index is legal
        return '?';
    return ((const char *)*this)[i]; // return palindrome[i]
}
Palindrome::operator const char *() const
{
    char *str = new char[size + 1];
    memcpy(str, (half + std::string(half.rbegin() + size % 2, half.rend())).c_str(), size); // palindrome is half + half_mirrored
    str[size] = '\0';
    return str;
}
bool Palindrome::operator<(const Palindrome &other) const
{
    return toLower(half) < toLower(other.half); // call operator < from string with lower_case
}
std::ostream &operator<<(std::ostream &out, const Palindrome &other)
{
    const char *tmp = (const char *)other;
    out << tmp; // use conversion operator
    delete[] tmp;
    return out;
}
std::istream &operator>>(std::istream &in, Palindrome &other)
{
    std::string str;
    in >> str;
    other = str; // operator =
    return in;
}
bool Palindrome::isLegal(char c) // check if c is '0'-'9' or 'a'-'A' or 'z'-'Z'
{
    return (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}
bool Palindrome::isPalindrome(const std::string &other) // check if string is a palindrome
{
    for (int i = 0; i < other.length() / 2; i++)
        if (!isLegal(other[i]) || other[i] != other[other.length() - i - 1])
            return false;
    return true;
}