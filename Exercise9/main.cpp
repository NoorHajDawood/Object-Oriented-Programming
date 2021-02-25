#include "simple.h"
#include "person.h"


int main()
{
	C c;
	c.B::m_test = 5;


	TA ta(5);
	cout << ta.m_num;
	ta.m_num = 8;
	ta.m_num = 10;
}
