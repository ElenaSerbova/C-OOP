#include <iostream>
using namespace std;

class A {
public:    
    int fieldA = 0;
    
    void MethodA() { cout << "MethodA" << endl; }

    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
};


class B : virtual public A
{
public:
    
    int fieldB = 0;
    
    void MethodB() { cout << "MethodB" << endl; }

    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }
};

class C : virtual public A
{
public:

    int fieldC = 0;

    void MethodC() { cout << "MethodC" << endl; }

    C() { cout << "C()" << endl; }
    ~C() { cout << "~C()" << endl; }
};


class D : public B, public C
{
public:

    int fieldD = 0;

    void MethodD() { cout << "MethodD" << endl; }

    D() { cout << "D()" << endl; }
    ~D() { cout << "~D()" << endl; }
};


int main()
{
    D obj;
    obj.fieldA = 10;
    obj.fieldB = 20;
    obj.fieldC = 30;
    obj.fieldD = 40;
}

