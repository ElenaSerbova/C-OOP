#include <iostream>
using namespace std;

#include "Time.h"

int main()
{
    Time time; //вызывается его конструктор

    time.SetHours(9);
    time.SetMinutes(35);
    //time.SetSeconds(0);

    cout << time.GetHours() << " : "
        << time.GetMinutes() << " : "
        << time.GetSeconds() << endl;

    //Invoke constructors
    Time time1; //default constructor
    Time time2(12, 34, 50);
    Time time3(12, 30);
    Time time4(12);
}

