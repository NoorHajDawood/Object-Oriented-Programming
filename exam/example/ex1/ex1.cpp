#include "ex1.h"

typedef array<double> T1;
typedef array<int> T2;
typedef arraySize<double, 5> T3;
typedef arraySize<double, 8> T4; // arraySize<double, ...>   IS - A    array<double>

int main(int argc, char const *argv[])
{
    try
    {
        T1 a1(12), a11(10); // -10ו 12 בגודל double של מערכים 2 הגדרת
        T2 a2(10);          // 10 בגודל int של מערך הגדרת
        a2 = a11;           // Syntax error
        a1 = a11;           // O.K.
        a1[5] = a2[4];      // O.K.
        cout << a1;

        const T1 ca1(a11);
        ca1 = a11;       // Syntax error
        ca1[2] = a11[3]; // Syntax error
        a11[3] = ca1[2]; // O.K.

        double c_array[] = {0.5, -7, 3.14, 0., 3}; // "C מערך "הגדרת
        T1 a12(c_array, 4);
        T3 a3;
        T4 a4;
        a3[1] = a4[2]; // O.K.
        a3 = a4;       // Syntax error
        a4 = a3;       // Syntax error
        a1 = a4;       // O.K.    -->  a1 = static_cast<array<double>>(a4);
    }
    catch (Bad_Index exc)
    {
        cerr << exc;
    }
    return 0;
}
