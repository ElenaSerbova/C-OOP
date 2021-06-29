#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
void mySwap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<>
void mySwap<char[20]>(char (&a) [20], char (&b) [20])
{
    size_t size = strlen(a) + 1;
    char* tmp = new char[size];
    
    strcpy_s(tmp, size, a);
    strcpy_s(a, size, b);
    strcpy_s(b, size, tmp);

    delete[] tmp;
}

int main()
{
    int a = 5, b = 7;
    mySwap(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    int c = 10, d = 20;
    mySwap(c, d);

    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    double e = 23.4, f = 34.5;
    mySwap(e, f);

    cout << "e = " << e << endl;
    cout << "f = " << f << endl;

    char str1[20] = "aaaaaa";
    char str2[20] = "bbbbbb";

    mySwap(str1, str2);

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
 
}
