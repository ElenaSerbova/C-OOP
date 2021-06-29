#include <iostream>
#include "DynamicArray.h"

using namespace std;

class Date {
public:
    int year = 0;
    int month = 0;
    int day = 0;
};

int main()
{
    DynamicArray<int> array;
    array.Add(100);
    array.Add(200);
    array.Add(300);

    DynamicArray<int> copyArray = array;

    for (size_t i = 0; i < copyArray.GetSize(); i++)
    {
        cout << copyArray[i] << "\t";
    }

    cout << endl;

    DynamicArray<Date> dates;

    Date d{ 2021, 2, 22 };
    dates.Add(d);

    dates.Add(Date{ 2021, 3, 1 });
    dates.Add(Date{ 2021, 5, 17 });

    for (size_t i = 0; i < dates.GetSize(); i++)
    {
        cout << "Date " << i << ": ";
        cout << dates[i].day << ".";
        cout << dates[i].month << ".";
        cout << dates[i].year << endl;
    }


    double arr1[5] = { 1,2,3,4,5 };
    DynamicArray<double> arr2 = { 1,2,3,4,5 };

}

