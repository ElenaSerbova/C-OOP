#include <iostream>
#include "List.h"

int main()
{
    List<int> list;
    list.Print();
    list.ReversePrint();

    cout << "Insert first item" << endl;
    list.InsertItem(0, 100);
    list.Print();
    list.ReversePrint();
    
    cout << "Add items" << endl;
    list.AddItem(10);
    list.AddItem(20);
    list.AddItem(30);
    list.Print();
    list.ReversePrint();

    cout << "Insert to end" << endl;
    list.InsertItem(4, 200);
    list.Print();
    list.ReversePrint();

    cout << "Insert to start" << endl;
    list.InsertItem(0, 200);
    list.Print();
    list.ReversePrint();

    cout << "Insert in midst" << endl;
    list.InsertItem(2, 300);
    list.Print();
    list.ReversePrint();

    
}
