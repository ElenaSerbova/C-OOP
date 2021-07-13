#include <iostream>
using namespace std;

class A
{
public:

    int field = 0;
    int fieldA = 0;

    void Method() { cout << "A::Method" << endl; }
    void MethodA() { cout << "MethodA" << endl; }

    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
};

class B
{
public:

    int field = 0;
    int fieldB = 0;

    void Method() { cout << "B::Method" << endl; }
    void MethodB() { cout << "MethodB" << endl; }

    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }
};

class C : public A, public B
{
public:

    int fieldC = 0;

    void MethodC() { cout << "MethodC" << endl; }

    C() : B(), A() { cout << "C()" << endl; }
    ~C() { cout << "~C()" << endl; }
};

template<typename T>
class TemplateA : public A
{
public:
    T fieldA;
};


template<class T>
class TemplateB : public TemplateA<T>
{
public:
    T fieldB;
};

class D : public TemplateB<int>
{

};


int main()
{
    C obj1;
    obj1.fieldA = 1;
    obj1.fieldB = 2;
    obj1.fieldC = 3;
    obj1.A::field = 4;
    obj1.B::field = 5;

    obj1.MethodA();
    obj1.MethodB();
    obj1.MethodC();
    obj1.A::Method();
    obj1.B::Method();

    TemplateB<int> obj2;
    obj2.fieldA = 0;
    obj2.fieldB = 0;
}
