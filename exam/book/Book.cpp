#include "Book.h"
#include <iostream>
#include <cstring>
#include <exception>
using namespace std;

Book::Book() { book_name = NULL; };
Book::~Book() { delete[] book_name;  cout << "Base Book\n";}

void Book::set_catalog_number(int num) { catalog_number = num; }

int Book::get_catalog_number() const { return catalog_number; }

void Book::set_book_name(String name)
{
   if (book_name != NULL)
      delete[] book_name;
   book_name = new char[strlen(name) + 1];
   strcpy(book_name, name);
}

String Book::get_book_name() const
{
   if (book_name == NULL)
   {
      throw exception();
   }

   char *tmp = new char[strlen(book_name) + 1];
   return strcpy(tmp, book_name);
}

Boolean Book::book_name_is_set() const
{
   if (book_name != NULL)
      return TRUE;
   return FALSE;
}