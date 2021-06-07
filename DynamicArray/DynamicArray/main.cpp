#include <iostream>
using namespace std;

#include "DynamicArray.h"

int main()
{
    DynamicArray arr;

    arr.AddElement(10);
    arr.AddElement(20);
    arr.AddElement(30);

    for (size_t i = 0; i < arr.GetSize(); i++)
    {
        cout << arr.GetElement(i) << "\t";
    }
    cout << endl;
}

