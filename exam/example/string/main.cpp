#include "point.h"

int main()
{
    Point_Size p_size1("abc"), p_size2("ij"), p_size3;
    Point_Null p_null1("defgh"), p_null2("klmnop"), p_null3;

    cout << endl;
    p_size1 = p_size1 + p_null1; // abc + defgh
    p_size1.print();             // Point Size abcdefgh

    cout << endl;
    p_null3 = p_null1 + p_size1; // defgh + abc
    p_null3.print();             // Point null defghabc

    cout << endl;
    p_null3 = p_size2 + p_null2; // ij + klmnop
    p_null3.print();             // Point null ijklmnop

    cout << endl;
    p_size1 = p_size1 + p_null3; // abcdefgh + ijklmnop
    p_size1.print();             // Point Size abcdefghijklmnop

    return 0;
}