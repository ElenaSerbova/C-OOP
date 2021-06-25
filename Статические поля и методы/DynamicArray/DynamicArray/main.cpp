#include <iostream>
#include <ctime>
#include "DynamicArray.h"
using namespace std;

void ConstructorsTest();
void AccessorsTest();
void AddElementTest();
void CopyCostructorTest();
void ReturnObjectTest();
void IndexatorTest();


void PrintArray(DynamicArray arr);
DynamicArray GenerateRandomArray(size_t size);



int main()
{
    srand(time(0));      
   
    //ConstructorsTest();
    //AccessorsTest();
    //AddElementTest();
    //CopyCostructorTest();
    //ReturnObjectTest();
    IndexatorTest();
}

void ConstructorsTest()
{
    DynamicArray array1; //DynamicArray() - default contructor 
    DynamicArray array2(5); //DynamicArray(5)
    DynamicArray array3(5, 10); //DynamicArray(5, 10)

    cout << "array1 size: " << array1.GetSize() << endl;
    cout << "array2 size: " << array2.GetSize() << endl;
    cout << "array3 size: " << array3.GetSize() << endl;    
}

void AccessorsTest()
{
    DynamicArray array(5);

    for (size_t i = 0; i < array.GetSize(); i++)
    {
        array.SetElement(i, i + 1);
        cout << array.GetElement(i) << "\t";
    }
    cout << endl;

    array.SetElement(6, 100);
}

void AddElementTest()
{
    DynamicArray array(5, 10); //DynamicArray(5, 10)
    cout << "array size: " << array.GetSize() << endl;

    array.AddElement(20);    

    for (size_t i = 0; i < array.GetSize(); i++)
    {
        cout << array.GetElement(i) << "\t";
    }
    cout << endl;
}

void CopyCostructorTest()
{
    DynamicArray arr1(5, 100);

    //Конструктор копирования вызывается в следующих случаях:  

    //1. При создании нового объекта на основе существующего
    DynamicArray arr2 = arr1; //DynamicArray(arr1) конструктор копирования

    //2. При передаче в функцию по значению
    PrintArray(arr1); //копирование arr1 в параметр функции
    PrintArray(arr2); //копирование arr2 в параметр функции

    //3. При возврате объекта из функции по значению
    DynamicArray arr3 = GenerateRandomArray(10); //копирование возвращаемого значения в arr3
                                                     
    //В следующей ситуации не используется конструктор копирования                                            
    DynamicArray arr4(5, 10);
    arr4 = arr1 = arr2; //opertor=
    PrintArray(arr4);

    cout << "-----" << endl;
    //самоприсваивание
    DynamicArray& arr5 = arr4;

    arr4 = arr5;
    PrintArray(arr4);
}

void ReturnObjectTest()
{
    DynamicArray arr1 = GenerateRandomArray(100000);
    PrintArray(arr1);

    DynamicArray arr2(4, 1);
    arr2 = GenerateRandomArray(10);

    PrintArray( GenerateRandomArray(10) );
}

void IndexatorTest()
{
    DynamicArray arr = GenerateRandomArray(10);

    arr[0] = 100;    

    for (size_t i = 0; i < arr.GetSize(); i++)
    {
        cout << arr[i] << "\t"; //arr.operator[](i)
    }
    cout << endl;

    const DynamicArray& arrRef = arr;

    for (size_t i = 0; i < arrRef.GetSize(); i++)
    {
        cout << arrRef[i] << "\t"; //arr.operator[](i) const
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
} //локальные параметры удаляются (вызов деструктора)

DynamicArray GenerateRandomArray(size_t size)
{
    DynamicArray arr(size);

    for (size_t i = 0; i < arr.GetSize(); i++)
    {
        arr.SetElement(i, rand() % 100);
    }

    return arr; //1. move, 2. delete
}
