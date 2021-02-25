#include <sstream>
#include <iostream>
#include "Calendar.h"

// Calendar::Calendar() : currentDate(), eventArray(nullptr)
// {
//     eventArray = new Event *[CALENDAR_MAXSIZE]; // allocation of the dates array
//     if (!eventArray)
//     {
//         cerr << "Dynamic allocation Error";
//         exit(1);
//     }
//     else
//         memset(eventArray, 0, CALENDAR_MAXSIZE * sizeof(Event *)); // setting the arrays fields to 0
// }

Calendar::Calendar(int currentDay = 0, int currentMonth = 0, int CurrentYear = 0) : currentDate(currentDay, currentMonth, CurrentYear), eventArray(nullptr)
{
    eventArray = new Event *[CALENDAR_MAXSIZE]; // allocation of the dates array
    if (!eventArray)
    {
        cerr << "Dynamic allocation Error";
        exit(1);
    }
    else
        memset(eventArray, 0, CALENDAR_MAXSIZE * sizeof(Event *)); // setting the arrays fields to 0
}
Calendar::~Calendar() // destructor
{
    for (int i = 0; i < CALENDAR_MAXSIZE; i++) // free each allocated date in the array
    {
        if (eventArray[i] != 0)
            delete eventArray[i];
    }
    delete[] eventArray; // free the array
}

bool Calendar::isEventClashing(const Event &event) const //	check if the event clashes with another in the array
{
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (eventArray[i] && eventArray[i]->eventClash(event))
            return true;
    }
    return false;
}

int Calendar::setEvent(const Event &newEvent, int num) // num and date don't matter for num
{
    // make sure the arguments are legal
    if (num < 0 || num >= CALENDAR_MAXSIZE)
    {
        std::cerr << "index is incorrect" << endl;
        return -1;
    }
    if (newEvent.getStartDate().get_day() == 0 || newEvent.getPresenter() == nullptr || newEvent.getEndDate().isBefore(newEvent.getStartDate()))
    {
        std::cerr << "one or more of the events info are illegal" << endl;
    }
    if (newEvent.getEventNumber() <= 0)
    {
        std::cerr << "event number has to be positive" << endl;
        return -1;
    }
    int index = findEvent(newEvent.getEventNumber());
    if (index != -1 && index != num)
    {
        std::cerr << "there already exists an event with same number in index: " << index << endl;
        return -1;
    }
    Event *tmp = eventArray[num];
    eventArray[num] = nullptr;
    if (isEventClashing(newEvent))
    {
        std::cerr << "event clashes with another existing event" << endl;
        return -1;
    }
    eventArray[num] = tmp;
    if (eventArray[num] == nullptr) // if date doesn't exist allocate it
    {
        eventArray[num] = new Event(newEvent);
        if (!eventArray[num])
        {
            cerr << "Dynamic allocation Error";
            return -1;
        }
    }
    else
    {
        *(eventArray[num]) = newEvent; // replace existing date's fields
    }

    return 0;
}
bool Calendar::isFree(int num) const
{
    // make sure the arguments are legal
    if (num < 0 || num >= CALENDAR_MAXSIZE || eventArray[num] != 0)
        return false;
    return true;
}
int Calendar::firstFree() const
{
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (eventArray[i] == 0)
            return i;
    }
    return -1;
}

int Calendar::insert(const Event &newEvent)
{
    // make sure the arguments are legal
    if (newEvent.getEventNumber() <= 0)
    {
        std::cerr << "event number has to be positive" << endl;
        return -1;
    }
    int index = findEvent(newEvent.getEventNumber());
    if (index != -1)
    {
        std::cerr << "there already exists an event with same number in index: " << index << endl;
        return -1;
    }
    index = firstFree();
    if (index == -1)
    {
        std::cerr << "no empty place" << endl;
        return -1;
    }
    if (newEvent.getStartDate().get_day() == 0 || newEvent.getPresenter() == nullptr || newEvent.getEndDate().isBefore(newEvent.getStartDate()))
    {
        std::cerr << "one or more of the events info are illegal" << endl;
        return -1;
    }
    if (isEventClashing(newEvent))
    {
        std::cerr << "event clashes with another existing event" << endl;
        return -1;
    }
    if (!(eventArray[index] = new Event(newEvent)))
    {
        cerr << "Dynamic allocation Error";
        return -1;
    }
    return 0;
}
int Calendar::oldest() const
{
    if (isEmpty())
        return -1;
    int minIndex = -1;
    Event *min = 0;
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (min == 0 && eventArray[i] != 0) // find first object and mark it as the oldest
        {
            minIndex = i;
            min = eventArray[i];
        }
        else
        {
            if (eventArray[i] && !min->getStartDate().isBefore(eventArray[i]->getStartDate())) // found an older date
            {
                minIndex = i;
                min = eventArray[i];
            }
        }
    }
    return minIndex;
}
int Calendar::findEvent(int eventNumber) const
{
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (eventArray[i] && eventArray[i]->getEventNumber() == eventNumber)
            return i;
    }
    return -1;
}
void Calendar::deleteAll()
{
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        delete eventArray[i];
    }
}
int Calendar::deleteEvent(int index)
{
    if (index < 0 || index >= CALENDAR_MAXSIZE)
        return -1;
    delete eventArray[index];
    return 0;
}
char *Calendar::print() const
{
    char *str;
    if (isEmpty())
    {
        str = new char[15];
        strcpy(str, "Empty Calendar");
        return str;
    }
    char *tmp;
    stringstream strout;

    std::cout << "_________________________________" << endl << "Calendar Information:" << endl << "Current Date: ";
    tmp = currentDate.print();
    std::cout << endl;
    strout << "_________________________________" << endl << "Calendar Information:" << endl << "Current Date: " << tmp << endl;
    
    delete[] tmp;
    for (int i = 0, count = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (eventArray[i] != 0)
        {
            std::cout << "_________________________________" << endl << "Event #" << ++count << endl;
            strout << "_________________________________" << endl <<  "Event #" << count << endl;
            tmp = eventArray[i]->print();
            strout << tmp;
            delete[] tmp;
        }
    }
    str = new char[strout.str().length() + 1];
    str[strout.str().length()] = 0;
    strcpy(str, strout.str().c_str());
    return str;
}
void Calendar::sortEvents()
{
    for (int n = CALENDAR_MAXSIZE - 1; n >= 0; n--)
    {
        for (int i = 0; i < n; i++)
        {
            if (eventArray[i] == 0)
            {
                eventArray[i] = eventArray[i + 1];
                eventArray[i + 1] = nullptr;
            }
            else if (eventArray[i + 1] != 0) // bubble sort
            {
                if (!eventArray[i]->getStartDate().isBefore(eventArray[i + 1]->getStartDate()))
                {
                    swap(eventArray[i], eventArray[i + 1]);
                }
            }
        }
    }
}
bool Calendar::isEmpty() const
{
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (eventArray[i] != 0)
            return false;
    }
    return true;
}

int Calendar::changeDate(int eventNumber, MyDate &dateStart, MyDate &dateEnd)
{
    // make sure event exists
    int index = findEvent(eventNumber);
    if (index == -1)
    {
        std::cerr << "event doesn't exist" << endl;
        return -1;
    }
    // make sure the arguments are legal
    if (!dateEnd.isBefore(dateStart) || dateStart.get_day() == 0)
    {
        std::cerr << "dates are illegal" << endl;
        return -1;
    }
    Event tmp;
    tmp.setStartDate(dateStart);
    tmp.setEndDate(dateEnd);
    Event *tmp2 = eventArray[index];
    eventArray[index] = nullptr;
    if (isEventClashing(tmp))
    {
        std::cerr << "event clashes with another existing event" << endl;
        return -1;
    }
    eventArray[index] = tmp2;
    eventArray[index]->setStartDate(dateStart);
    eventArray[index]->setEndDate(dateEnd);
    return 0;
}

int Calendar::GetMonthEvents() const
{
    int count = 0;
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (eventArray[i] && eventArray[i]->getStartDate().get_month() == currentDate.get_month() && eventArray[i]->getStartDate().get_day() >= currentDate.get_day())
            count++;
    }
    return count;
}

Event **Calendar::UpcomingEvents() const
{
    int length = GetMonthEvents();
    if (length == 0)
        return nullptr;
    Event **array = new Event *[length];
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (eventArray[i] && eventArray[i]->getStartDate().get_month() == currentDate.get_month() && eventArray[i]->getStartDate().get_day() >= currentDate.get_day())
            array[i] = new Event(*eventArray[i]);
    }
    return array;
}

Event **Calendar::getEventArray() const
{
    return eventArray;
}

MyDate Calendar::getCurrentDate() const
{
    return currentDate;
}

const Event *Calendar::getEvent(int index) const
{
    if (index < 0 || index >= CALENDAR_MAXSIZE)
        return nullptr;
    return eventArray[index];
}

int Calendar::setEventArray(Event **array)
{
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (array[i]->getPresenter() == nullptr)
            return -1;
        for (int j = i + 1; j < CALENDAR_MAXSIZE && array[i]; j++)
        {
            if (array[j] == nullptr)
                continue;
            if (array[i]->getEventNumber() == array[j]->getEventNumber() || !array[i]->eventClash(*array[j]) || array[j]->getPresenter() == nullptr)
                return -1;
        }

        if (eventArray[i] == nullptr && array[i] != nullptr)
            eventArray[i] = new Event(*array[i]);
        else if (eventArray[i] != nullptr && array[i] != nullptr)
            eventArray[i] = array[i];
        else
        {
            delete eventArray[i];
            eventArray[i] = nullptr;
        }
    }
    return 0;
}

void Calendar::setCurrentDate(int currentDay, int currentMonth, int CurrentYear)
{
    currentDate.set(currentDay, currentMonth, CurrentYear);
}

void swap(void *&x, void *&y) // swap function for two pointers of any type
{
    void *tmp = x;
    x = y;
    y = tmp;
}