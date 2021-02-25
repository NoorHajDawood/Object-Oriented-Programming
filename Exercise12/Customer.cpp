#include "Customer.h"

ostream& operator << (ostream& out, const Customer& customer)
{
	out << customer._id << " " << customer._name << " " << customer._address;
    return out;
}

void Customer::save (ofstream& out) const
{
    size_t len = _name.length();
	out.write((char*)&len, sizeof(len));
    out.write(_name.data(), len);
    
    len = _id.length();
    out.write((char*)&len, sizeof(len));
    out.write(_id.data(), len);
    
    len = _address.length();
    out.write((char*)&len, sizeof(len));
    out.write(_address.data(), len);
    
}
void Customer::load (ifstream& in)
{
    size_t len;
    in.read((char*)&len, sizeof(len));
    _name.resize(len);
    in.read((char*)_name.data(), len);
    
    in.read((char*)&len, sizeof(len));
    _id.resize(len);
    in.read((char*)_id.data(), len);
    
    in.read((char*)&len, sizeof(len));
    _address.resize(len);
    in.read((char*)_address.data(), len);
}
