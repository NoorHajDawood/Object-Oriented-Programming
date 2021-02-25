#pragma once

#include <iostream> 

using namespace std;

class Person {
public:
	Person(int x = 0) { cout << "Person::Person("<< x <<") called" << endl; m_num = x; }

public:
	int m_num;
};


class Faculty : virtual public Person {
public:
	Faculty(int x) :Person(x) { cout << "Faculty::Faculty("<< x <<") called" << endl;}
};


class Student : virtual public Person {
public:
	Student(int x) :Person(x) { cout << "Student::Student("<< x <<") called" << endl;}
};


class TA : public Faculty, public Student {
public:
	TA(int x) : Person(x), Faculty(x), Student(x) {cout << "TA::TA("<< x <<") called" << endl;}
};

/*-----------------------------------------------------------------------------------------*/

//#include<iostream> 
//
//using namespace std;

// class Person {
// public:
// 	Person(int x):m_num(x) { cout << "Person::Person(int) called" << endl; }
// 	//Person() { cout << "Person::Person() called" << endl; }

// public:
// 	int m_num;
// };


// class Faculty : virtual public Person {
// public:
// 	Faculty(int x) :Person(x) { cout << "Faculty::Faculty(int) called" << endl; }
// };


// class Student : virtual public Person {
// public:
// 	Student(int x) :Person(x) { cout << "Student::Student(int) called" << endl;}
// };


// class TA : public Student, public Faculty  {
// public:
// 	TA(int x) :Person(x), Student(x), Faculty(x) { cout << "TA::TA(int) called" << endl;}
// };