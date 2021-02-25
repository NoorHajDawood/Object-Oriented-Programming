#include <iostream>
#include <string.h>
#include "Car.h"


using namespace std;
/*---------------------------------------------------------------------------------------------------------*/
Car::Car(const char* manu, int year, double price, int* licenseNo) 
	:
	m_year(year), 
	m_price(price)
{
    m_manufacturer = new char[strlen(manu) + 1];
	//strncpy_s()
    strncpy(m_manufacturer, manu, strlen(manu) + 1);
	memcpy(m_licenseNo, licenseNo, LICENSE_LENGTH * sizeof(int));

    /*for (int i = 0; i < LICENSE_LENGTH; ++i)
        m_licenseNo[i] = licenseNo[i];*/
}
/*---------------------------------------------------------------------------------------------------------*/
Car::Car(const Car& car) 
	: 
	m_price(car.m_price), 
	m_year(car.m_year)
{
    m_manufacturer = new char[strlen(car.m_manufacturer) + 1];
	//strncpy_s(m_manufacturer, strlen(car.m_manufacturer) + 1, car.m_manufacturer, strlen(car.m_manufacturer));
	strncpy(m_manufacturer, car.m_manufacturer, strlen(car.m_manufacturer) + 1);
	memcpy(m_licenseNo, car.m_licenseNo, LICENSE_LENGTH * sizeof(int));

    /*for (int i = 0 ; i < LICENSE_LENGTH; ++i)
        m_licenseNo[i] = car.m_licenseNo[i];*/
}
/*---------------------------------------------------------------------------------------------------------*/
Car::~Car()
{
	delete[] m_manufacturer; 
}
/*---------------------------------------------------------------------------------------------------------*/
void Car::print(void) const
{
	cout << "Manufacturer:" << m_manufacturer << endl;
	cout << "Year:" << m_year << endl;
	cout << "Price:" << m_price << endl;
	cout << "License No. :" << endl;

	for (int i = 0; i < LICENSE_LENGTH; ++i)
		cout << m_licenseNo[i] << " ";

	cout << endl;
}
/*---------------------------------------------------------------------------------------------------------*/
void Car::setManufacturer(const char *manufacturer)
{
	if (nullptr == manufacturer)
		return;

    delete[] m_manufacturer;
	m_manufacturer = new char[strlen(manufacturer) + 1];
	strncpy(m_manufacturer, manufacturer, strlen(manufacturer) + 1);
	//strncpy_s(m_manufacturer, strlen(manufacturer) + 1, manufacturer, strlen(manufacturer));
}
/*---------------------------------------------------------------------------------------------------------*/