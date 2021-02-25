#include "Event.h"
#include <string.h>
#include <sstream>
#include <iostream>

Event::Event() : eventNumber(0), name(nullptr), presenter(nullptr), dateStart(), dateEnd() {}

Event::Event(const int eventNumber, const char *name, const char *presenter, const MyDate &dateStart, const MyDate &dateEnd)
    : eventNumber(eventNumber), name(nullptr), presenter(nullptr), dateStart(dateStart), dateEnd(dateEnd)
{
    int len;
    char *tmp;
    if (name != nullptr) // copy name
    {
        len = strlen(name) + 1;
        tmp = new char[len];
        memcpy(tmp, name, len);
        this->name = tmp;
    }
    if (presenter != nullptr) // copy presenter's name
    {
        len = strlen(presenter) + 1;
        tmp = new char[len];
        memcpy(tmp, presenter, len);
        this->presenter = tmp;
    }
}
Event::Event(const Event &other)
    : eventNumber(other.eventNumber), name(nullptr), presenter(nullptr), dateStart(other.dateStart), dateEnd(other.dateEnd)
{
    int len;
    char *tmp;
    if (other.name != nullptr) // copy name
    {
        len = strlen(other.name) + 1;
        tmp = new char[len];
        memcpy(tmp, other.name, len);
        this->name = tmp;
    }
    if (other.presenter != nullptr) // copy presenter's name
    {
        len = strlen(other.presenter) + 1;
        tmp = new char[len];
        memcpy(tmp, other.presenter, len);
        this->presenter = tmp;
    }
}

Event::~Event()
{
    delete[] name;
    delete[] presenter;
}

int Event::getEventNumber() const
{
    return eventNumber;
}
const char *Event::getName() const
{
    return name;
}
const char *Event::getPresenter() const
{
    return presenter;
}
MyDate Event::getStartDate() const
{
    return MyDate(dateStart);
}
MyDate Event::getEndDate() const
{
    return MyDate(dateEnd);
}

void Event::setEventNumber(const int eventNumber)
{
    this->eventNumber = eventNumber;
}
void Event::setName(const char *name)
{
    if (name == nullptr)
        return;
    int len = strlen(name) + 1; // copy name
    char *tmp = new char[len];
    memcpy(tmp, name, len);
    delete this->name;
    this->name = tmp;
}
void Event::setPresenter(const char *presenter)
{
    if (presenter == nullptr)
        return;
    int len = strlen(presenter) + 1; // copy presenter's name
    char *tmp = new char[len];
    memcpy(tmp, presenter, len);
    delete this->presenter;
    this->presenter = tmp;
}
void Event::setStartDate(const MyDate &dateStart)
{
    if (this->dateStart.get_day() == 0 || dateStart.isBefore(this->dateEnd) && dateStart.get_day() != 0)
        this->dateStart.copy_date(dateStart);
}
void Event::setEndDate(const MyDate &dateEnd)
{
    if (this->dateEnd.get_day() == 0 || this->dateStart.isBefore(dateEnd))
        this->dateEnd.copy_date(dateEnd);
}

Event &Event::operator=(const Event &other)
{
    if(&other == this)
        return *this;
    eventNumber = other.eventNumber;
    int len;
    char *tmp;
    delete[] name;
    delete[] presenter;
    if (other.name != nullptr) // copy name
    {
        len = strlen(other.name) + 1;
        tmp = new char[len];
        memcpy(tmp, other.name, len);
        name = tmp;
    }
    else
        name = nullptr;
    if (other.presenter != nullptr) // copy presenter's name
    {
        len = strlen(other.presenter) + 1;
        tmp = new char[len];
        memcpy(tmp, other.presenter, len);
        presenter = tmp;
    }
    else
        presenter = nullptr;
    dateStart = other.dateStart; // copy dates
    dateEnd = other.dateEnd;

    return *this;
}

char *Event::print() const // print event info and return it
{
    stringstream strout;
    strout << "Event Number: " << eventNumber << endl;
    if (name)
        strout << "Event Name: " << name << endl;
    if (presenter)
        strout << "Event Presenter: " << presenter << endl;
    std::cout << strout.str() << "Event Starts at: ";
    char *tmp = dateStart.print();
    strout << "Event Starts at: " << tmp << endl;
    std::cout << endl
              << "Event Ends at: ";
    delete[] tmp;
    tmp = dateEnd.print();
    strout << "Event Ends at: " << tmp << endl;
    std::cout << endl;
    delete[] tmp;
    int len = strout.str().length() + 1;
    char *str = new char[len];
    strncpy(str, strout.str().c_str(), len);
    return str;
}

bool Event::eventClash(const Event &other) const //  check with another event if both happen during the same time
{
    if(this->dateEnd.isBefore(other.dateStart) || other.dateEnd.isBefore(this->dateStart))
        return false;
    return true;
}