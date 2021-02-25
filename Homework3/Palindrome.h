#pragma once
#include <string>
#include <iostream>
class Palindrome
{
public:
    Palindrome(const std::string& other= "");
    
    Palindrome(const Palindrome& other);
    ~Palindrome();

    Palindrome& operator=(const Palindrome& other);
    Palindrome& operator+=(const Palindrome& other);
    Palindrome& operator+=(char c);
    Palindrome& operator-=(const Palindrome& other);
    Palindrome operator+(const Palindrome& other) const;
    Palindrome operator++(int);
    bool operator==(const Palindrome& other) const;
    Palindrome operator!() const;
    char operator[](int i) const;
    operator const char*() const;
    bool operator<(const Palindrome& other) const;

private:
    std::string half;
    int size;
    static bool isLegal(char c);    // check if c is '0'-'9' or 'a'-'A' or 'z'-'Z'
    static bool isPalindrome(const std::string& other); // check if string is a palindrome
    static std::string toLower(std::string lower);  // convert string to lower_case
};
std::ostream& operator<<(std::ostream &out, const Palindrome &other);
std::istream& operator>>(std::istream &in, Palindrome &other);
