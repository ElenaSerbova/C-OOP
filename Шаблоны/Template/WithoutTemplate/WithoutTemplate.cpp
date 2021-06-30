#include <iostream>
#include <string>
using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void swap(bool& a, bool& b)
{
	bool tmp = a;
	a = b;
	b = tmp;
}

void swap(string& a, string& b)
{
	string tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int num1 = 10;
	int num2 = 20;
	swap(num1, num2);
	cout << num1 << "\t" << num2 << endl;

	bool b1 = true;
	bool b2 = false;
	swap(b1, b2);
	cout << b1 << "\t" << b2 << endl;

	string str1 = "tratata";
	string str2 = "blalalala";
	swap(str1, str2);
	cout << str1 << "\t" << str2 << endl;

}
