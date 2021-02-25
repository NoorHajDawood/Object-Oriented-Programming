#pragma once

#define LICENSE_LENGTH 8

class Car
{
public:
	Car(){}
    Car(const char* manu, int year, double price, int* licenseNo);
    Car(const Car& car);
	~Car();

public:
    void		print(void) const;
    void		setManufacturer(const char* manufacturer);
    const char*	getManufacturer() const { return m_manufacturer; }

private:
    int			m_licenseNo[LICENSE_LENGTH];
    char*		m_manufacturer;
    int			m_year;
    double		m_price;
};