#include <iostream>
#include "Fraction.h"
using namespace std;

#pragma region function helpers

void Print(const Fraction& fr)
{    
    cout << fr.GetNumerator()  //Fracion::GetNumerator(&fr)
        << " / " 
        << fr.GetDenominator() //Fracion::GetDenominator(&fr)
        << endl;
}

void foo(Fraction fr)
{
    cout << "foo: " << endl;
    Print(fr);
}

#pragma endregion

#pragma region function declaration

void ConstMethodTest();
void ExplicitCtorTest();
void OperatorMultipleTest(); //operator*
void OperatorDivideTest(); //operator/
void UnaryOperatorTest(); //operator-
void IncrementTest(); //operator++
void DecrementTest(); //operator--
void EqualsTest(); //operator==
void ConversionTest();

#pragma endregion


int main()
{ 
   // ConstMethodTest();
   // ExplicitCtorTest();
   // OperatorMultipleTest();
   // OperatorDivideTest();
   // UnaryOperatorTest();
   // IncrementTest();
   // DecrementTest();
   // EqualsTest();
    ConversionTest();
}

void ConstMethodTest()
{
    Fraction fr1;
    Fraction fr2(1, 2);
    Fraction fr3(1);

    Print(fr1);
    Print(fr2);
    Print(fr3);
}

void ExplicitCtorTest()
{
    Fraction fr3(1);
    Print(fr3);

    foo((Fraction)10); //foo( Fraction(10) )
}

void OperatorMultipleTest()
{
    Fraction fr1(2, 3);
    Fraction fr2(3, 4);

    cout << "2/3 * 3/4 = ";

    Fraction result = fr1 * fr2; // Fraction result = operator*(fr1, fr2);
    Print(result);
   
    cout << "2/3 * 4 = ";

    result = fr1 * 4; //result = operator*(fr1, 4);
    Print(result);

    cout << "2 * 3/4 = ";

    result = 2 * fr2; //result = operator*(2, fr2);
    Print(result);
}

void OperatorDivideTest()
{
    Fraction fr1(1, 2);
    Fraction fr2(2, 3);

    cout << "1/2 : 2/3 = ";
    
    Fraction result = fr1 / fr2; //Fraction result = fr1.operator/ ( fr2 );
    Print(result);

    cout << "1/2 : 3 = ";

    result = fr1 / 3; //result = fr1.operator/ ( 3 );
    Print(result);

    cout << "3 : 2/3 = ";

    result = 3 / fr2; //result = operator/ (3, fr2 );
    Print(result);

}

void UnaryOperatorTest()
{
    Fraction fr(1, 2);
    Print(-fr);
}

void IncrementTest()
{
    Fraction fr(1, 2);

    cout << "++(1/2):  " << endl;
    Fraction result = ++fr; //operator++(fr)

    cout << "Result = ";
    Print(result);

    cout << "Fraction = ";
    Print(fr);

    cout << "(3/2)++:  " << endl;
    result = fr++; //operator++(fr, 0)

    cout << "Result = ";
    Print(result);

    cout << "Fraction = ";
    Print(fr);
}

void DecrementTest()
{
    Fraction fr(5, 2);

    cout << "--(5/2):  " << endl;
    Fraction result = --fr; //fr.operator--() -> this = &fr

    cout << "Result = ";
    Print(result);

    cout << "Fraction = ";
    Print(fr);

    cout << "(3/2)--:  " << endl;
    result = fr--; //fr.operator--(0)

    cout << "Result = ";
    Print(result);

    cout << "Fraction = ";
    Print(fr);
}

void EqualsTest()
{
    Fraction fr1(1, 2);
    Fraction fr2(1, 2);
    Fraction fr3(2, 3);

    cout << "fr1 == fr2 : " << (fr1 == fr2 ? "true" : "false") << endl;
    cout << "fr1 != fr2 : " << (fr1 != fr2 ? "true" : "false") << endl;
    cout << "fr1 == fr3 : " << (fr1 == fr3 ? "true" : "false") << endl;
    cout << "fr1 != fr3 : " << (fr1 != fr3 ? "true" : "false") << endl;
}

void ConversionTest()
{
     //1. из другого типа в ваш тип
    Fraction fr1 = (Fraction)1;

    //2. из вашего типа в другой
    Fraction fr2(1, 2);
    
    double d = (double)fr2;

    cout << "d: " << d << endl;

    int i = (int)fr2; //fraction -> int

    cout << "i: " << i << endl;

}
