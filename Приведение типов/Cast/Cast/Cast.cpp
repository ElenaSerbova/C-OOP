#include <iostream>
using namespace std;

#include "Animal.h"

void TestCCast()
{
    int a = 12;
    double d = (double)a;

    int* p = &a;
    int b = (int)p;

    int* p2 = (int*)a;

    cout << b << endl;
    cout << p2 << endl;

    Animal* animal = new Bird;
    Bird* bird = (Bird*)animal;
    Cat* cat = (Cat*)animal;
}

void TestStaticCast()
{
    int a = 12;
    double d = static_cast<double>(a);

    //int* p = static_cast<int*>(a); //invalid type conversion

    //Animal* a = new Bird;
    //Bird* b = static_cast<Bird*>(a);
    //Cat* c = static_cast<Cat*>(a);
}

void TestDynamicCast()
{
    Animal* animal = new Bird;

    Bird* bird = dynamic_cast<Bird*>(animal);

    if (bird != nullptr)
    {
        bird->Print();
        bird->ChikChirik();
    }

    animal = new Cat;

    bird = dynamic_cast<Bird*>(animal);

    if (bird != nullptr)
    {
        bird->Print();
        bird->ChikChirik();
    }

}

void foo(const int& r)
{
    int& r1 = const_cast<int&>(r);
}

void TestConstCast()
{
    int a = 12;
    foo(a);
}


void TestReinterpretCast()
{
    int a = 12;

    int* p = reinterpret_cast<int*>(a);

    cout << p << endl;
}
int main()
{
   // TestCCast();
   //TestStaticCast();
    TestDynamicCast();
   // TestReinterpretCast();
}

