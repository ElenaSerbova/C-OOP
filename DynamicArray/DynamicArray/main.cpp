#include <iostream>
#include <ctime>
using namespace std;

#include "DynamicArray.h"


void PrintArray(DynamicArray arr);
DynamicArray CreateRandomArray(int size);

void DestructorTest();
void ConstructorTest();
void CopyTest();

int main()
{
    srand((unsigned int)time(0));

    //ConstructorTest();
    //DestructorTest();
    //CopyTest();

    DynamicArray arr = CreateRandomArray(10);
    const DynamicArray& rArr = arr;
    //rArr.AddElement(10);
    rArr.GetSize();
    
    
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

void CopyTest()
{
    DynamicArray arr1;
    arr1.AddElement(10);
    arr1.AddElement(20);
    arr1.AddElement(30);

    //1. копирование объекта при создании
    DynamicArray arr2 = arr1;
    arr2.AddElement(40);

    //2. Передача в функцию по значению
    PrintArray(arr1);
    PrintArray(arr2);

    //3. возврат по значению
    DynamicArray arr3 = CreateRandomArray(10);
}

void PrintArray(DynamicArray arr)
{
    for (size_t i = 0; i < arr.GetSize(); i++)
    {
        cout << arr.GetElement(i) << "\t";
    }
    cout << endl;
}

DynamicArray CreateRandomArray(int size)
{
    DynamicArray array(size);

    for (size_t i = 0; i < size; i++)
    {
        array.SetElement(i, rand() % 100);
    }
    return array;
}

