#include <iostream>
using namespace std;

template<typename T>
T sum(T num1, T num2)
{
    cout << "template1" << endl;
    return num1 + num2;
}

////before C++ 11
//template<typename T1, typename T2>
//T2 sum(T1 num1, T2 num2)
//{
//    cout << "template2" << endl;
//    return num1 + num2;
//}

//C++ 11
//template<typename T1, typename T2>
//auto sum(T1 num1, T2 num2) -> decltype(num1 + num2)
//{
//    cout << "template2" << endl;
//    auto res = num1 + num2;
//    return res;
//}

//C++ 14
//template<typename T1, typename T2>
//decltype(auto) sum(T1 num1, T2 num2)
//{
//    cout << "template2" << endl;
//    auto res = num1 + num2;
//    return res;
//}

//C++ 17
template<typename T1, typename T2>
auto sum(T1 num1, T2 num2)
{
    cout << "template2" << endl;
    auto res = num1 + num2;
    return res;
}

int main()
{
    cout << sum(12, 23) << endl;
    cout << sum(12.4, 23.5) << endl;
    cout << sum(12, 34.5) << endl;
    cout << sum(12.4, 34) << endl;
    cout << sum<long, float>(12, 34.5) << endl;

    decltype(12 + 23.4) res = 12 + 23.4;
    auto a = 12;
    auto b = 23.4;
}
