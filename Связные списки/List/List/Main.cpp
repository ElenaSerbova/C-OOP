#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    try
    {
        List<int> list;

        //list[0] = 10;

        list.AddToFront(50);

        list.AddToBack(10);
        list.AddToBack(20);
        list.AddToBack(30);

        list.AddToFront(40);

        list.Print(); //40  50  10  20  30

        list[0] = 0;
        list[2] = 0;
        list[4] = 0;

        //list.RemoveAt(0);
        list.Print();
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }
}
