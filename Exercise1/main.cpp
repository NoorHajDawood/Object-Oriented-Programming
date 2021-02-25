#include <iostream>
#include <cstring>
#include "Log.h"

using namespace std;

#define SIZE 10

int Multiply(int a, int b)
{
	return a * b;
}

void MultiplyAndLog(int a, int b)
{
	cout << a * b << endl;
}


void MultiplyAndLog(int a, float b)
{
	cout << a * b << endl;
}


int main()
{
	const int* max2 = 0;
	int k=5;
	max2 = &k;
	cout << "Hello CPP!!!" << endl;
	

	/*Create new variable with simple arithmetic operations*/
	int x = 0;
	x = x * 3;
	x = 5;

	/*Variables types*/
	//Boolean
	bool isTrue = false;//true

	//Charecter
	char letter = 't';

	//Numbers
	int number = 2;
	float decimal = 5.5f;
	double ddecimal = 5.5;
	signed int s_number = -5;
	unsigned int us_number = 5;
	long int l_number = 120;
	long long int ll_number = 120;

	cout << sizeof(number) << endl;
	cout << sizeof(decimal) << endl;
	cout << sizeof(ddecimal) << endl;
	cout << sizeof(ll_number) << endl;

	cout << number << endl;


	/*Conditions*/
	if (number > 0)
		cout << "The number is: " << number << endl;
	else
		cout << "The number is negative!" << endl;

	//Shorten if
	number > 0 ? number++ : number += 5;
	// Exp       If True       else


	/*Switch*/
	switch (number)
	{
	case 1:
		cout << "The number is: 1" << endl;
		break;
	case 2:
		cout << "The number is: 2" << endl;
		break;
	case 3:
		cout << "The number is: 3" << endl;
		break;
	case 4:
		cout << "The number is: 4" << endl;
		break;
	default:
		break;
	}


	/*Functions*/
	Log("Hello this is Jony!");


	MultiplyAndLog(5, 6);
	MultiplyAndLog(5, 4);
	MultiplyAndLog(7.5f, 9.5f);



	/*Loops*/
	//For
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			cout << i << endl;
	}


	//While
	int i = 0;
	while (i < 10)
	{
		if (i % 2 == 0)
			cout << i << endl;

		++i;
	}

	//Do While
	i = 0;
	do
	{
		if (i % 2 == 0)
			cout << i << endl;

		++i;
	} while (i < 10);


	/*Allocations*/

	//****Alocate Single variable****
	int * num = new int;
	*num = 5;
	cout << *num << endl;

	//Delete single allocation
	delete num;



	//****Allocate arrays****
	int* arr = new int[SIZE];
	if (arr == nullptr)
		cout << "Allocation failed!" << endl;

	//Initialize the memory to zero
	memset(arr, 0, SIZE * sizeof(int));

	//Print only the address
	cout << arr << endl;

	//Print the array data
	for (int j = 0; j < SIZE; ++j)
		cout << arr[j] << endl;

	//Delete array allocation
	delete [] arr;
	


	cin.get();
	return 0;
}	