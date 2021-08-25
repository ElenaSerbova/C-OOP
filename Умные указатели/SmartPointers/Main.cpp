#include <iostream>
using namespace std;

#include "SmartPointer.h"

class Item {
public:
	Item() {
		cout << "Item created" << endl;
	}

	~Item() {
		cout << "Item deleted" << endl;
	}

	void setNum(int n) {}
};

void foo()
{
	SmartPointer<Item> p;
	SmartPointer<Item> ptr = new Item;
	
	int num;
	cout << "Enter a number: ";
	cin >> num;


	if (num == 0)
		return;

	ptr->setNum(num);	
}

void bar()
{
	SmartPointer<Item> ptr = new Item;	

	int num;
	cout << "Enter a number: ";
	cin >> num;

	if (num == 0)
		throw exception();

	ptr->setNum(num);	
}

int main()
{
	foo();

	try {
		bar();
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
