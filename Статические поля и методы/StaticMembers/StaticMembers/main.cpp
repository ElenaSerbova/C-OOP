#include <iostream>
using namespace std;

#include "Time.h"
#include "TestClass.h"
#include "Counter.h"

void TimeTest();
void StaticFieldTest();
void CounterTest();

int main()
{
    //TimeTest();
    //StaticFieldTest();
    CounterTest();    

}

void TimeTest()
{
    Time now; //создание объекта с полями
    now.hours = 9;
    now.minutes = 51;
    now.seconds = 30;


    Time startLesson;
    startLesson.hours = 9;
    startLesson.minutes = 0;
    startLesson.seconds = 0;

}

void StaticFieldTest()
{
    cout << "Static field: " << TestClass::staticField << endl;
    TestClass::staticField = 1;

    TestClass obj1;
    obj1.field1 = 10;
    obj1.field2 = 20;
    obj1.staticField = 100;    

    TestClass obj2;
    obj2.field1 = 30;
    obj2.field2 = 40;
    obj2.staticField = 200;

    cout << obj1.field1 << ", " << obj1.field2
        << ", " << obj1.staticField
        << endl;

    cout << obj2.field1 << ", " << obj2.field2 
         << ", " << obj2.staticField
         << endl;

    cout << "Static field: " << TestClass::staticField << endl;

}

void CounterTest()
{
    cout << "Count: " << Counter::GetCount() << endl;

    Counter obj1;
    cout << "Count: " << Counter::GetCount() << endl;
    
    {    
        Counter obj2;
        cout << "Count: " << Counter::GetCount() << endl;
    
        Counter obj3;
        cout << "Count: " << Counter::GetCount() << endl;
    }

    cout << "Count: " << Counter::GetCount() << endl;
}