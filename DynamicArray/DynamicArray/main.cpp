#include <iostream>
using namespace std;

#include "DynamicArray.h"


void PrintArray(DynamicArray arr);
void DestructorTest();
void ConstructorTest();

int main()
{
    //ConstructorTest();
    //DestructorTest();

    DynamicArray arr1;
    arr1.AddElement(10);
    arr1.AddElement(20);
    arr1.AddElement(30);

    PrintArray(arr1);


    DynamicArray arr2 = arr1;
    arr2.AddElement(40);
    PrintArray(arr2);
}

void DestructorTest() {
    DynamicArray arr(100);
    cout << "DestructorTest" << endl;
}

void ConstructorTest()
{
    DynamicArray arr(10);
    //.....
    arr.Clear();

    arr.AddElement(10);
    arr.AddElement(20);
    arr.AddElement(30);

    for (size_t i = 0; i < arr.GetSize(); i++)
    {
        cout << arr.GetElement(i) << "\t";
    }
    cout << endl;
}

void PrintArray(DynamicArray arr)
{
    for (size_t i = 0; i < arr.GetSize(); i++)
    {
        cout << arr.GetElement(i) << "\t";
    }
    cout << endl;
}

