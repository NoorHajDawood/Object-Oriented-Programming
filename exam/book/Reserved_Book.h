#pragma once
#include "Book.h"
#include <iostream>
using namespace std;

class Reserved_Book : public Book
{
private:
    int fine;

public:
    Reserved_Book(/* args */) : fine(0) {}
    Reserved_Book(const Reserved_Book &other) : fine(other.fine) { *this = static_cast<const Book&>(other); }
    ~Reserved_Book() { cout << "Resereved\n";}

    int get_fine() const { return fine; }
    void set_fine(int f) { fine = f; }

    void print()
    {
        cout << "name: " << get_book_name() << endl
             << "number: " << get_catalog_number() << endl
             << "fine: " << fine << endl;
    }

    // Reserved_Book &operator=(const Reserved_Book &other)
    // {
    //     Book::operator=(other);
    //     fine = other.fine;
    //     return *this;
    // }

    Book &operator=(const Book &other)
    {
        //Reserved_Book *a = dynamic_cast<Reserved_Book *>(this);
        const Reserved_Book *b = dynamic_cast<const Reserved_Book *>(&other);
        if(b)
            fine = b->fine;
        set_catalog_number(other.get_catalog_number());
        set_book_name(other.get_book_name());
        return *this;
    }
};