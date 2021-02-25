#pragma once

#include "Car.h"

#define MAX_NO_CARS 5

class Garage
{
public:
    Garage();
    Garage(const Garage& garage);
    ~Garage();

public:
    bool	addCarByIndex(const Car& car, int index);
    bool	deleteCarByIndex(int index);
    void	print() const;
    bool	addCar();

private:
    Car*	m_cars[MAX_NO_CARS];
    int		m_noCars;
};