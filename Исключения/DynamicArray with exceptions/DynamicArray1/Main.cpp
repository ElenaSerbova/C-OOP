#include <iostream>
#include <time.h>
#include "DynamicArray.h"
#include "IndexOutOfRange.h"
#include "MemoryAllocateException.h"
using namespace std;

void Foo(DynamicArray array)
{
    array.Print();
} //локальные параметры удаляются (вызов деструктора)


DynamicArray Bar()
{   
    DynamicArray array;
    array.Add(100);
    array.Add(200);
    array.Add(300);

    try {
        array.RemoveAt(210);
    }
    catch (const index_out_of_range& ex)
    {
        cout << ex.what() << endl;
    }

    return array; // копирование во временный объект, 
                  // а затем вызов деструктора для локального параметра
}

void function(const DynamicArray& array)
{   
    for (size_t i = 0; i < array.GetSize(); i++)
    {
        cout << "element " << i << " => " << array[i] << endl;
    }
}

int main()
{
    srand(time(0));

    try 
    {
        DynamicArray array(5);
        array.Add(1);
        array.Add(2);
        array.Add(3);
        array.Add(4);

        array.Print();

        DynamicArray array1(10);

    }     
    catch (index_out_of_range& ex) 
    {       
        cout << ex.what() << endl;       
    }  
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }   
    catch (...) //catch-all
    {
        cout << "some error" << endl;
    } 
}

