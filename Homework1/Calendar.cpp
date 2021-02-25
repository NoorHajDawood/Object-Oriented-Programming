#include <sstream>
#include <iostream>
#include "Calendar.h"

void swap(void*& x, void*& y) // swap function for two pointers of any type
{
    void* tmp = x;
    x = y;
    y = tmp;
}

Calendar::Calendar() // constructor
: dateArray(new MyDate*[CALENDAR_MAXSIZE])
{
    // dateArray = new MyDate *[CALENDAR_MAXSIZE]; // allocation of the dates array
    if (!dateArray)
        cerr << "Dynamic allocation Error";
    else
        memset(dateArray, 0, CALENDAR_MAXSIZE * sizeof(MyDate *));  // setting the arrays fields to 0
}
Calendar::~Calendar()   // destructor
{
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)  // free each allocated date in the array
    {
        if (dateArray[i] != 0)
            delete dateArray[i];
    }
    delete[] dateArray; // free the array
}

int Calendar::setDate(const MyDate &newDate, int num)
{
    if (num < 0 || num >= CALENDAR_MAXSIZE) // check num correctness
        return -1;
    if (dateArray[num] == 0)    // if date doesn't exist allocate it
    {
        MyDate *date = new MyDate(newDate.get_day(), newDate.get_month(), newDate.get_year());
        if (!date)
        {
            cerr << "Dynamic allocation Error";
            return -1;
        }
        dateArray[num] = date;
    }
    else
    {
        dateArray[num]->copy_date(newDate); // replace existing date's fields
    }

    return 0;
}
bool Calendar::isFree(int num)
{
    if (num < 0 || num >= CALENDAR_MAXSIZE || dateArray[num] != 0)
        return false;
    return true;
}
int Calendar::firstFree()
{
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (dateArray[i] == 0)
            return i;
    }
    return -1;
}
int Calendar::insert(const MyDate &newDate)
{
    int index = firstFree();
    if (index == -1)
        return -1;
    if (!(dateArray[index] = new MyDate(newDate.get_day(), newDate.get_month(), newDate.get_year())))
    {
        cerr << "Dynamic allocation Error";
        return -1;
    }
    return 0;
}
int Calendar::oldest()
{
    if (isEmpty())
        return -1;
    int minIndex = -1;
    MyDate *min = 0;
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (min == 0 && dateArray[i] != 0 && dateArray[i]->get_day())   // find first object and mark it as the oldest
        {
            minIndex = i;
            min = dateArray[i];
        }
        else
        {
            if (dateArray[i] && dateArray[i]->get_day() && !min->isBefore(*dateArray[i]))   // found an older date
            {
                minIndex = i;
                min = dateArray[i];
            }
        }
    }
    return minIndex;
}
int Calendar::datesNum(const MyDate &newDate)
{
    int counter = 0;
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (dateArray[i] && dateArray[i]->isEqual(newDate))
            counter++;
    }
    return counter;
}
void Calendar::deleteAll()
{
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (dateArray[i] != 0)
        {
            MyDate zero;
            dateArray[i]->copy_date(zero);
        }
    }
}
int Calendar::deleteDate(int num)
{
    if (num < 0 || num >= CALENDAR_MAXSIZE || dateArray[num] == 0)
        return -1;
    MyDate zero;
    dateArray[num]->copy_date(zero);
    return 0;
}
char *Calendar::print()
{
    char *str;
    if (isEmpty())  // empty dates array
    {
        str = new char[15];
        strcpy(str,"Empty Calendar");
        return str;
    }
    stringstream strout;
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if(dateArray[i] != 0)
        {
            char* datePrint = dateArray[i]->print();   // get dates print
            strout << datePrint << ' ';                 // insert it to the stream
            std::cout << ' ';
            delete[] datePrint;                         // free its memory
        }
    }
    str = new char[strout.str().length()+1];        // convert the stream to char *
    str[strout.str().length()] = 0;
    strcpy(str, strout.str().c_str());
    return str;
}
void Calendar::sortDates()
{
    for (int n = CALENDAR_MAXSIZE - 1; n >= 0; n--)
    {
        for (int i = 0; i < n; i++)
        {
            if (dateArray[i] == 0)                  // make sure that zero'd dates are towards the end
            {
                dateArray[i] = dateArray[i + 1];
            }
            else if(dateArray[i]->get_day() == 0)  // make sure nullptr are at the end
            {
                swap(dateArray[i], dateArray[i+1]);
            }
            else if (dateArray[i + 1] != 0)         // bubble sort
            {
                if (!dateArray[i]->isBefore(*dateArray[i + 1]))
                {
                    swap(dateArray[i], dateArray[i+1]);
                }
            }
        }
    }
}
bool Calendar::isEmpty() const
{
    for (int i = 0; i < CALENDAR_MAXSIZE; i++)
    {
        if (dateArray[i] != 0)
            return false;
    }
    return true;
}