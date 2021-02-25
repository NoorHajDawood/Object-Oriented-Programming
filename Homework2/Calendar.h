#pragma once
#include "MyDate.h"
#include "Event.h"

#define CALENDAR_MAXSIZE 30

class Calendar
{
public:
	Calendar(int currentDay = 0, int currentMonth = 0, int CurrentYear = 0);
	~Calendar();

public:
	// methods
	int setEvent(const Event &newEvent, int num);	// change/add an event
	bool isFree(int num) const;						// check if this index is free
	int firstFree() const;							// find first free index
	int insert(const Event &newEvent);				// add an event
	int oldest() const;								// find oldest event
	int findEvent(int eventNumber) const;			// find an events index
	void deleteAll();								// delete all events
	int deleteEvent(int index);						// delete an event in index
	char *print() const;							// print the calendar
	void sortEvents();								// sort events from oldest to newest
	bool isEmpty() const;							//	is calendar empty
	int changeDate(int eventNumber, MyDate &dateStart, MyDate &dateEnd);	//	change an event's start and end dates
	int GetMonthEvents() const;						//	count how many events are in this month yet to happen
	Event **UpcomingEvents() const;					//	return an array of the events that didnt happen yet in this month
	bool isEventClashing(const Event &event) const;	//	check if the event clashes with another in the array
	// get
	Event **getEventArray() const;
	MyDate getCurrentDate() const;
	const Event* getEvent(int index) const;				// get event in index
	// set
	int setEventArray(Event **array);
	void setCurrentDate(int currentDay, int currentMonth, int CurrentYear);

private:
	Event **eventArray;
	MyDate currentDate;
};
