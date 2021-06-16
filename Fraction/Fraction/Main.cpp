#include <iostream>
using namespace std;
#include "Fraction.h"

int main()
{
    Fraction fr1(1, 2);
    fr1.Print();

    Fraction fr2(2, 3);
    fr2.Print();

    Fraction res = fr1 * fr2; //operator*(fr1, fr2)
    res.Print();

    res = fr1 * 2; 
    res.Print();

    res = 2 * fr2;
    res.Print();

    res = fr1 / fr2; //fr1.operator/(fr2);
    res.Print();

    res = fr1 / 3;
    res.Print();

    res = 3 / fr2;
    res.Print();
}