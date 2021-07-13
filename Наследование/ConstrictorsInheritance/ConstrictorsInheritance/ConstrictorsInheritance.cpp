#include <iostream>
using namespace std;

class A
{
    int a;
public:
    //A() { cout << "A()" << endl; }
    A(int value) { cout << "A(int)" << endl; }
    ~A() { cout << "~A()" << endl; }
};

class B : public A
{
    int b;
public:
    B() : A(0) { cout << "B()" << endl; }
    B(int value) : A(value) { cout << "B(int)" << endl; }
    B(double value ) : A(0) { cout << "B(double)" << endl; }
    ~B(){ cout << "~B()" << endl; }

};

int main()
{
    B obj1;
    cout << endl;

   /* B obj2{0};
    cout << endl;

    B obj3(10.0);*/
}

