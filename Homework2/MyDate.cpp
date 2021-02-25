#include <sstream>
#include <iostream>
#include "MyDate.h"

MyDate::MyDate() : m_day(0), m_month(0), m_year(0) {}
MyDate::MyDate(int day, int month, int year)
{
    if (month < 1 || month > 12 || day < 1 || day > 30 || (day > 28 && month == 2) || year < 1900 || year > 2100)
    {
        m_day = 0;
        m_month = 0;
        m_year = 0;
    }
    else
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }
}
MyDate::MyDate(const MyDate &other)
{
    m_day = other.m_day;
    m_month = other.m_month;
    m_year = other.m_year;
}
void MyDate::init()
{
    m_day = 22;
    m_month = 11;
    m_year = 2020;
}
bool MyDate::isBefore(const MyDate &newDate) const
{
    if ((m_year < newDate.m_year) ||
        (m_year == newDate.m_year && m_month < newDate.m_month) ||
        (m_year == newDate.m_year && m_month == newDate.m_month && m_day < newDate.m_day))
        return true;
    return false;
}
bool MyDate::operator==(const MyDate& other) const
{
    return m_year == other.m_year && m_month == other.m_month && m_day == other.m_day;
}
int MyDate::delay(int num)
{
    if (num < 0 || num > 365)
    {
        return -1;
    }
    int beforeDay = m_day;
    int beforeMonth = m_month;
    int beforeYear = m_year;
    while (num > 0)
    {
        if (m_month == 2 && num + m_day > 28)
        {
            m_month++;
            num -= 28 - m_day;
            m_day = 0;
        }
        else if (num + m_day <= 30)
        {
            m_day += num;
            return 0;
        }
        else
        {
            if (m_month == 12)
            {
                m_year++;
                m_month = 1;
                num -= 30 - m_day;
                m_day = 0;
            }
            else
            {
                m_month++;
                num -= 30 - m_day;
                m_day = 0;
            }
        }
    }
    if (m_year > 2100) // if new date is not legal then revert
    {
        m_day = beforeDay;
        m_month = beforeMonth;
        m_year = beforeYear;
        return -1;
    }
    return 0;
}
int MyDate::bringForward(int num)
{
    if (num < 0 || num > 365)
    {
        return -1;
    }
    int beforeDay = m_day;
    int beforeMonth = m_month;
    int beforeYear = m_year;
    while (num > 0)
    {
        if (m_day - num < 0)
        {
            m_month--;
            num -= m_day;
            if (m_month == 2)
            {
                m_day = 28;
            }
            else
            {
                m_day = 30;
                if (m_month == 0)
                {
                    m_year--;
                    m_month = 12;
                }
            }
        }
        else
        {
            m_day = m_day - num;
            return 0;
        }
    }
    if (m_year < 1900) // if new date is not legal then revert
    {
        m_day = beforeDay;
        m_month = beforeMonth;
        m_year = beforeYear;
        return -1;
    }
    return 0;
}
char *MyDate::print() const
{
    stringstream strout;
    strout << m_day << '/' << m_month << '/' << m_year;
    char *str = new char[strout.str().length() + 1];
    str[strout.str().length()] = 0;
    strcpy(str, strout.str().c_str());
    std::cout << str;
    return str;
}
bool MyDate::copy_date(const MyDate &new_date)
{
    m_day = new_date.m_day;
    m_month = new_date.m_month;
    m_year = new_date.m_year;
    return true;
}
int MyDate::set(int day, int month, int year)
{
    if (!(month < 1 || month > 12 || day < 1 || day > 30 || (day > 28 && month == 2) || year < 1900 || year > 2100))
    {
        m_day = day;
        m_month = month;
        m_year = year;
        return 0;
    }
    return -1;
}
int MyDate::setDay(int day)
{
    if (!(day < 1 || day > 30 || (day > 28 && m_month == 2)))
    {
        m_day = day;
        return day;
    }
    return -1;
}
int MyDate::setMonth(int month)
{
    if (!(month < 1 || month > 12 || (m_day > 28 && month == 2)))
    {
        m_month = month;
        return month;
    }
    return -1;
}
int MyDate::setYear(int year)
{
    if (!(year < 1900 || year > 2100))
    {
        m_year = year;
        return year;
    }
    return -1;
}
int MyDate::get_day() const
{
    return m_day;
}
int MyDate::get_year() const
{
    return m_year;
}
int MyDate::get_month() const
{
    return m_month;
}
bool MyDate::isEqual(const MyDate &other) const
{
    return m_day == other.m_day && m_month == other.m_month && m_year == other.m_year;
}