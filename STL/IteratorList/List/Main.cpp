#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List<int> list;
    list.AddItem(10);
    list.AddItem(20);
    list.AddItem(30);

    for (auto it = list.begin(); it != list.end(); it++)
    {
        cout << *it << endl;
    }
}
