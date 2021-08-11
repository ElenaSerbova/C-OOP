#include <iostream>
#include <string>
using namespace std;

class DivideByZeroException
{
public:
    DivideByZeroException()
    {
        _message = "Error: divide by zero";
        _line = 0;
    }

    DivideByZeroException(int line, string funcName)
    {
        _message = "Error: divide by zero";
        _line = line;
        _funcName = funcName;
    }

    string GetMessage() const
    {
        return _message;
    }

    int GetLine() const
    {
        return _line;
    }

    string GetFuncionName() const
    {
        return _funcName;
    }

private:
    string _message;
    int _line;
    string _funcName;
};

double divide(double num1, double num2)
{    
    if (num2 == 0)
    {
        throw DivideByZeroException(__LINE__, __FUNCTION__);
    }

    return num1 / num2;
}

string function()
{
    throw string("Exception");
    return "text";
}

int main()
{
    try
    {
        double num1, num2;

        cout << "Enter number 1: ";
        cin >> num1;

        cout << "Enter number 2: ";
        cin >> num2;

        cout << "Result: " << divide(num1, num2) << endl;
        cout << function() << endl;
    }
    catch (const DivideByZeroException& ex)
    {
        cout << ex.GetMessage() << endl;
        cout << "Function: " << ex.GetFuncionName() << endl;
        cout << "Line: " << ex.GetLine() << endl;
    }
    catch (const string& str)
    {
        cout << str << endl;
    }

}

