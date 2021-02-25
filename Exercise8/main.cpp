#include <iostream>
#include <fstream>
#include "SuperMarket.h"

using namespace std;

int main (void)
{
    SuperMarket s;
    
    //Place Input.txt it within your 'working directory' or just replace the path below with an absolute path
    ifstream in("Input.txt");
    if (!in.is_open())
    {
        cerr<<"Could not open file: Input.txt\n";
        return -1;
    }
	in >> s; // Calls istream& operator >> (istream&, SuperMarket&)
    
	cout << s << endl; // Calls ostream& operator << (ostream&, const SuperMarket&)
    
    in.close();
    
    ofstream out("Copy.txt");
    if (!out.is_open())
    {
        cerr<<"Could not create file: Copy.txt\n";
        return -1;
    }
    
	out << s << endl;// Calls ostream& operator << (ostream&, const SuperMarket&)
    out.close();

	cin.get();
    return 0;
}