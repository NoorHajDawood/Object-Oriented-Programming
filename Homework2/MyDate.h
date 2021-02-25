#pragma once
#include <iostream>
#include "string.h"

using namespace std;

class MyDate
{
public:
	MyDate();
	MyDate(int day, int month, int year);
	MyDate(const MyDate& other);
	~MyDate() {};
	
public:	
	void init();
	bool isBefore(const MyDate& newDate) const;
	int delay(int num);
	int bringForward(int num);
	char* print() const;
	bool copy_date(const MyDate& new_date);
	
public:	
	// set functions
	int set(int day, int month, int year);
	int setDay(int day);
	int setMonth(int month);
	int setYear(int year);
	// get functions
	int get_day() const;
	int get_year() const;
	int get_month() const;
	// operator overloading
	bool operator==(const MyDate& other) const;	// operator ==
	// methods
	bool isEqual(const MyDate& other) const;	// check if this date equals other date

private:
	int m_day;
    int m_month;
    int m_year;
};

