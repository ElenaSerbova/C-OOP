#include <iostream>
#include <ctime>
#include "DynamicArray.h"
using namespace std;

void ConstructorsTest();
void AccessorsTest();
void AddElementTest();
void CopyCostructorTest();

void PrintArray(DynamicArray arr);
DynamicArray GenerateRandomArray(size_t size);

int main()
{
    srand(time(0));      
   
    //ConstructorsTest();
    //AccessorsTest();
    //AddElementTest();
    CopyCostructorTest();

    //DynamicArray array = GenerateRandomArray(10);
    //array.Sort();
    //PrintArray(array);

    //DynamicArray::Sort(array);
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

    //����������� ����������� ���������� � ��������� �������:  

    //1. ��� �������� ������ ������� �� ������ �������������
    DynamicArray arr2 = arr1; //DynamicArray(arr1) ����������� �����������

    //2. ��� �������� � ������� �� ��������
    PrintArray(arr1); //����������� arr1 � �������� �������
    PrintArray(arr2); //����������� arr2 � �������� �������

    //3. ��� �������� ������� �� ������� �� ��������
    DynamicArray arr3 = GenerateRandomArray(10); //����������� ������������� �������� � arr3
                                                     
    //� ��������� �������� �� ������������ ����������� �����������                                            
    DynamicArray arr4(5, 10);
    arr4 = arr1 = arr2; //opertor=
    PrintArray(arr4);

    cout << "-----" << endl;
    //����������������
    DynamicArray& arr5 = arr4;

    arr4 = arr5;
    PrintArray(arr4);
}

void PrintArray(DynamicArray arr)
{
    for (size_t i = 0; i < arr.GetSize(); i++)
    {
        cout << arr.GetElement(i) << "\t";
    }
    cout << endl;
} //��������� ��������� ��������� (����� �����������)

DynamicArray GenerateRandomArray(size_t size)
{
    DynamicArray arr(size);

    for (size_t i = 0; i < arr.GetSize(); i++)
    {
        arr.SetElement(i, rand() % 100);
    }

    return arr;
}
