#include <iostream>
#include <exception>
using namespace std;

void function1()
{
    cout << "function1 start" << endl;

    throw exception("exception in function1");

    cout << "function1 end" << endl;
}

void function2()
{
    cout << "function2 start" << endl;

    int* arr = new int[100];
   
    try
    {
        function1();
    }
    catch (exception& ex)
    {       
        delete[]arr;
        arr = nullptr;
        throw; //повторная генерация исключений
    }

    if (arr != nullptr) {
        delete[] arr;
    }

    cout << "function2 end" << endl;
}

int main()
{
    cout << "main start" << endl;

    try 
    {
        function2();
    }
    catch (exception& ex)
    {
        cout << "main: " << ex.what() << endl;
    }
    cout << "main end" << endl;


    try
    {

        int* arr = new int[100];
    }
    catch (bad_alloc& ex)
    {

    }

}

