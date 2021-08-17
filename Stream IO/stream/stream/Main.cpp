#include <iostream>
using namespace std;

void foo1()
{
	cout << "goodbit: " << cin.good() << endl;
	cout << "eofbit:  " << cin.eof() << endl;
	cout << "failbit: " << cin.fail() << endl;
	cout << "badbit:  " << cin.bad() << endl;

	int i;
	cout << "Enter number: ";
	cin >> i;

	cout << "goodbit: " << cin.good() << endl;
	cout << "eofbit:  " << cin.eof() << endl;
	cout << "failbit: " << cin.fail() << endl;
	cout << "badbit:  " << cin.bad() << endl;
}
void foo2()
{
	int i;
	while (cin.good())
	{
		cout << "Enter a number: ";
		cin >> i;

		if (!cin.good())
		{
			cout << "error" << endl;
			cin.clear();			
			cin.ignore();			
		}
		else
		{
			break;
		}
	}
}
void foo3()
{
	cin.exceptions(ios::badbit | ios::failbit);

	while (true)
	{
		try
		{
			int i;
			cout << "enter a number: ";
			cin >> i;
			break;
		}
		catch (ios::failure& ex)
		{
			cout << ex.what() << endl;
			cin.clear();
			cin.ignore();
		}
	}
}

int main()
{	
	//foo1();
	//foo2();
	foo3();
}