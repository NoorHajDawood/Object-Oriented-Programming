#pragma once
typedef char* String;
typedef enum { TRUE = 1 , FALSE = 0 } Boolean;

class Book {
protected:
   String book_name;
   int catalog_number;
public:
   Book();
   ~Book();

   void set_catalog_number(int num);
   int get_catalog_number() const;

   void set_book_name(String name);
   String get_book_name() const;
   Boolean book_name_is_set() const;

   virtual Book& operator=(const Book&) = 0;
};
