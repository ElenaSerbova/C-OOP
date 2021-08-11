#include <iostream>
using namespace std;

/*

int err_n = 0;

double divide(double a, double b)
{
    if (b == 0) {
        err_n = 1;
        return 0;
    }
    return a / b;
}


int main()
{   
    double a, b, res;

    cout << "Enter a number: ";
    cin >> a;

    cout << "Enter a number: ";
    cin >> b;

    res = divide(a, b);

    if (err_n != 0)
    {
        cout << "Divide by zero" << endl;
    }
    else
    {
        cout << "Result: " << divide(a, b) << endl;
    }

}

*/

double divide(double a, double b)
{
    if (b == 0) {
        throw "Divide by zero";
    }

    return a / b;
}

int main()
{
    try {
        double a, b, res;

        cout << "Enter a number: ";
        cin >> a;

        cout << "Enter a number: ";
        cin >> b;

        res = divide(a, b);

        cout << "Result: " << res << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }   

}