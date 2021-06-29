#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class A {
public: 
    void SetField(T value) {
        field = value;
    }
    T GetField() {
        return field;
    }
private:
    T field;
};


template<>
class A<char*>
{
public:
    A()
    {
        field = new char[100];
    }
    ~A() {
        delete[] field;
    }

    void SetField(const char* value) {
        strcpy_s(field, 100, value);
    }

    char* GetField() {
        return field;
    }
private:
    char* field = nullptr;

};

//частичная специализация

template<typename T1, typename T2>
class B {
public:
    T1 field1;
    T2 field2;
};

template<typename T1>
class B<T1, char*> {
public:
    T1 field1;
    char* field2;
};

int main()
{
    A<int> obj1;
    obj1.SetField(10);
    
    A<double> obj2;
    obj2.SetField(23.4);

    A<char*> obj3;
    obj3.SetField("Text");
}