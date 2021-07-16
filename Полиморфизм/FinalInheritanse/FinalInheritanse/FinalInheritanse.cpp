#include <iostream>
using namespace std;

class A {
public:
    virtual void Method() { 
        cout << "A::Method" << endl; 
    }
};

class B : public A {
public:
    virtual void Method() final {
        cout << "B::Method" << endl;
    }
};

class C : public B
{
public:
    virtual void Method()    {

    }
};

class D final {
public:
    void foo() {}
};

class E : public D {

};


int main()
{
    std::cout << "Hello World!\n";
}

