#include <iostream>
#include "Garage.h"

using namespace std;

int main ()
{
	int licenseNoT[] = { 1,2,3,4,5,6,7,8 };
	int licenseNoM[] = { 3,2,6,1,1,1,5,5 };
	int licenseNoS[] = { 2,2,1,2,2,2,1,1 };
	Car c1("Toyota", 2005, 100000, licenseNoT);
	Car c2("Mercedez", 2010, 200000, licenseNoM);
	Car c3("Skoda", 2009, 150000, licenseNoS);
    
    Garage garage;
	if (garage.addCarByIndex(c1, 0))
		cout << "Successfully added the Toyota car." << endl;
	if (garage.addCarByIndex(c2, 1))
		cout << "Successfully added the Mercedez car." << endl;
	if (garage.addCarByIndex(c3, 2))
		cout << "Successfully added the Skoda car." << endl;

    garage.print();
    
	if (garage.deleteCarByIndex(1))
		cout << "Successfully deleted the car @ index 1" << endl;
    
    garage.print();
    
	Garage garageCopy(garage);
    
    garageCopy.print();
	cin.get();
}