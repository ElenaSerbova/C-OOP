#include "Time.h"
#include <iostream>
using namespace std;

void printTime(Time time)
{
    cout << "Time: " << time.GetHours() << ":"
        << time.GetMinutes() << ":"
        << time.GetSeconds() << endl;
}

int main()
{
    Time time1;
    printTime(time1);

    Time time2(11, 24, 30);
    printTime(time2);

    Time time3(11, 25);
    printTime(time3);

    Time time4 = Time::GetCurrentTime();
    printTime(time4);
}
