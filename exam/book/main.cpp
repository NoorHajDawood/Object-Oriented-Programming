#include "Reserved_Book.h"

int main()
{
    //    Reserved_Book b;
    //    b.set_book_name("OOP");
    //    b.set_catalog_number(17);
    //    b.set_fine(7);

    //    Reserved_Book a = b;
    //    a.set_book_name("C++");

    //    a.print();
    //    b.print();

    Reserved_Book *b = new Reserved_Book;
    b->set_book_name("OOP");
    b->set_catalog_number(17);
    b->set_fine(7);

    Book *a = new Reserved_Book(*b);
    a->set_book_name("F++");
    
    dynamic_cast<Reserved_Book*>(a)->print();
    b->print();

    *a = *b;
    dynamic_cast<Reserved_Book*>(a)->print();
    b->print();

    delete b;
    return 0;
}
