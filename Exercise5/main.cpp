#include <iostream>
#include "String.h"

using namespace std;

int main (void)
{
    String s1 = "Hope for "; // Calls the String(const char*) constructor
    String s2 = "the best";
    
	if (s1 < s2) // calls operator < (const String&)
		cout << "s1 is lexicographically smaller than s2!" << endl;
    
    String s3 = ", but prepare";
    
    
    s1 += (s2 += s3); // calls operator += twice! (s2+=s3) comes first
    
    
    String s4 = s1 + " for the worst";
    
    
	for (int i = 0; i < s4.len(); ++i)
		cout << s4[i]; // calls operator[] for const objects
	cout << endl;
    
 
	String s5 = s4; // Copy constructor
    if (s5 == s4)
        cout<<"s5 and s4 are lexicographically equal!"<<endl;

    
    return 0;
}