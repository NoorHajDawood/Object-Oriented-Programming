#pragma once

#include <string>
#include <fstream>

using namespace std;

class Customer
{
public:
    Customer() {}

    Customer(const string& name, const string& id, const string& address) 
		: 
		_name(name), 
		_id(id), 
		_address(address) 
	{}
    
	Customer(const Customer& c)
	{
		_name = c._name;
		_id = c._id;
		_address = c._address;
	}

    friend ostream& operator << (ostream& out, const Customer& customer);
    
    bool operator == (const Customer& c) const { return _id == c._id; }
    
    void save (ofstream& out) const;
    void load (ifstream& in);

private:
    string _name;
    string _id;
    string _address;
};

