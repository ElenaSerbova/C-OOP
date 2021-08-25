#include <iostream>
using namespace std;

class Item {
public:
	Item(){
		cout << "Item created" << endl;
	}

	~Item()	{
		cout << "Item deleted" << endl;
	}

	void setNum(int n){}
};

void foo() 
{
	Item* ptr = new Item;

	int num;
	cout << "Enter a number: ";
	cin >> num;

	if (num == 0)
		return;

	ptr->setNum(num);

	delete ptr;
}

void bar()
{
	Item* ptr = new Item;

	int num;
	cout << "Enter a number: ";
	cin >> num;

	if (num == 0)
		throw exception();

	ptr->setNum(num);

	delete ptr;
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

