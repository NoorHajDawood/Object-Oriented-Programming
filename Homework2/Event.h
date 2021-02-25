#pragma one
#include "MyDate.h"

class Event
{
public:
    // constructors & destructors
    Event();
    Event(const int eventNumber, const char *name, const char *presenter, const MyDate &dateStart, const MyDate &dateEnd);
    Event(const Event& other);
    ~Event();
    // get functions
    int getEventNumber() const;
    const char *getName() const;
    const char *getPresenter() const;
    MyDate getStartDate() const;
    MyDate getEndDate() const;
    // set functions
    void setEventNumber(const int eventNumber);
    void setName(const char *name);
    void setPresenter(const char *presenter);
    void setStartDate(const MyDate &dateStart);
    void setEndDate(const MyDate &dateEnd);
    // operators
    Event& operator=(const Event& other);
    // methods
    char *print() const;                        // print event info and return it
    bool eventClash(const Event &other) const;  //  check with another event if both happen during the same time

private:
    int eventNumber;
    const char *name;
    const char *presenter;
    MyDate dateStart;
    MyDate dateEnd;
};