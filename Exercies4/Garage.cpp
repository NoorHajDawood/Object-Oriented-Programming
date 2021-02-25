#include <iostream>
#include <string.h>
#include "Garage.h"

using namespace std;

/*---------------------------------------------------------------------------------------------------------*/
Garage::Garage() 
	:
	m_noCars(0)
{
	memset(m_cars, 0 , MAX_NO_CARS * sizeof(Car*));
    /*for (int i = 0; i < MAX_NO_CARS; ++i)
        m_cars[i] = nullptr;*/
}
/*---------------------------------------------------------------------------------------------------------*/
Garage::Garage(const Garage& garage) 
	: 
	m_noCars(garage.m_noCars)
{
    for (int i = 0; i < MAX_NO_CARS; ++i)
    {
        if (nullptr != garage.m_cars[i])
            m_cars[i] = new Car(*garage.m_cars[i]);
        else
            m_cars[i] = nullptr;
    }
}
/*---------------------------------------------------------------------------------------------------------*/
Garage::~Garage()
{
	for (int i = 0; i < MAX_NO_CARS; ++i)
	{
		if (nullptr != m_cars[i])
			delete m_cars[i];
	}
}
/*---------------------------------------------------------------------------------------------------------*/
bool Garage::addCarByIndex(const Car& car, int index)
{
    if (index >= 0 && index < MAX_NO_CARS && nullptr == m_cars[index])//NULL != m_cars[index]
    {
        m_cars[index] = new Car(car);
        ++m_noCars;
        return true;
    }
    return false;
}
/*---------------------------------------------------------------------------------------------------------*/
bool Garage::addCar()
{
    int index;
    cout<<"Please enter index for the car."<<endl;
    cin>>index;
    
    if (!(index >= 0 && index < MAX_NO_CARS && nullptr != m_cars[index]))
        return false;

    char name[20]; 
	int year; 
	double price;
    int licenseNo[7];

    cout<<"Please enter a name for the car."<<endl;
    cin>>name;
    cout<<"Please enter year."<<endl;
    cin>>year;
    cout<<"Please enter price."<<endl;
    cin>>price;
    cout<<"Please enter license No."<<endl;
    for (int i = 0; i < LICENSE_LENGTH; ++i)
        cin>>licenseNo[i];
    
    m_cars[index] = new Car(name, year, price, licenseNo);
    ++m_noCars;

    return true;
}
/*---------------------------------------------------------------------------------------------------------*/
bool Garage::deleteCarByIndex(int index)
{
    if (index >= 0 && index < MAX_NO_CARS && m_cars[index])
    {
        delete m_cars[index];
        m_cars[index] = nullptr;
        --m_noCars;
        return true;
    }
    return false;
}
/*---------------------------------------------------------------------------------------------------------*/
void Garage::print(void) const
{
    for (int i = 0; i < MAX_NO_CARS; ++i)
        if (nullptr != m_cars[i])
            m_cars[i]->print();
}
/*---------------------------------------------------------------------------------------------------------*/