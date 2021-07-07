#include "Headers.h"

void GetFrontAndBackTest()
{
    cout << "======= GetFrontAndBackTest ========" << endl;
    List<int> list;

    try {
        cout << "head data: " << list.GetFront() << endl;
        cout << "tail data: " << list.GetBack() << endl;
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
}

void AddToFrontTest()
{
    cout << "======= AddToFront ========" << endl;

    List<int> list;
    list.AddToFront(10);

    cout << "size: " << list.GetSize() << endl;
    cout << "head data: " << list.GetFront() << endl;
    cout << "tail data: " << list.GetBack() << endl;

    list.AddToFront(20);

    cout << "size: " << list.GetSize() << endl;
    cout << "head data: " << list.GetFront() << endl;
    cout << "tail data: " << list.GetBack() << endl;

    list.Print();
    list.ReversePrint();
}

void AddToBackTest()
{
    cout << "======= AddToBack ========" << endl;

    List<int> list;
    list.AddToBack(10);

    cout << "size: " << list.GetSize() << endl;
    cout << "head data: " << list.GetFront() << endl;
    cout << "tail data: " << list.GetBack() << endl;

    list.AddToBack(20);

    cout << "size: " << list.GetSize() << endl;
    cout << "head data: " << list.GetFront() << endl;
    cout << "tail data: " << list.GetBack() << endl;

    list.Print();
    list.ReversePrint();
}

void RemoveSingleItemTest()
{
    cout << "======= RemoveSingleItem ========" << endl;
    List<int> list;
    list.AddToFront(100);

    list.RemoveByIndex(0);
    cout << "size: " << list.GetSize() << endl;

    list.Print();
    list.ReversePrint();
}

void RemoveFromFrontTest()
{
    cout << "======= RemoveFromFront ========" << endl;
    List<int> list;
    list.AddToBack(10);
    list.AddToBack(20);
    list.AddToBack(30); 
    list.AddToBack(40);

    list.RemoveByIndex(0);
    cout << "size: " << list.GetSize() << endl;
    cout << "head data: " << list.GetFront() << endl;

    list.Print();
    list.ReversePrint();
}

void RemoveFromBackTest()
{
    cout << "======= RemoveFromBack ========" << endl;
    List<int> list;
    list.AddToBack(10);
    list.AddToBack(20);
    list.AddToBack(30);
    list.AddToBack(40);

    list.RemoveByIndex(3);
    cout << "size: " << list.GetSize() << endl;
    cout << "tail data: " << list.GetBack() << endl;

    list.Print();
    list.ReversePrint();
}

int main()
{
    GetFrontAndBackTest();
    AddToFrontTest();
    AddToBackTest();
    RemoveSingleItemTest();
    RemoveFromFrontTest();
    RemoveFromBackTest();
}
