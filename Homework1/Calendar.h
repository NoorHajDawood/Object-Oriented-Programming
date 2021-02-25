#pragma once
#include "MyDate.h"

#define CALENDAR_MAXSIZE 30

class Calendar
{
public:
	Calendar();
	~Calendar();

public:	
	int setDate(const MyDate& newDate, int num);
	bool isFree(int num);
	int firstFree();
	int insert(const MyDate& newDate);
	int oldest();
	int datesNum(const MyDate& newDate);
	void deleteAll();
	int deleteDate(int num);
	char* print();
	void sortDates();

private:
	MyDate** dateArray;;
	bool isEmpty() const;
};

