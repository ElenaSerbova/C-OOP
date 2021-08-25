#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Item {
public:
	Item() {
		cout << "Item created" << endl;
	}

	~Item() {
		cout << "Item deleted" << endl;
	}

	void setNum(int n) {}

	int field;
};

void bar(unique_ptr<Item>& up)
{

}

void UsingUniquePtr()
{
    unique_ptr<Item> p(new Item);
	unique_ptr<Item[]> arr(new Item[3]);

    p->field = 100;
    cout << "integer: " << p->field << endl;

	p = nullptr;

	if (!p) {
		cout << "nullptr" << endl;
	}

	p.reset(new Item);

	p->field = 200;
	cout << "integer: " << p->field << endl;

	unique_ptr<Item> p1 = move(p);

	if (!p) {
		cout << "nullptr" << endl;
	}

	bar(p1);
}

void UsingSharedPtr()
{
	shared_ptr<Item> ptr(new Item);

	ptr->field = 10;
	cout << "integer: " << ptr->field << endl;

	shared_ptr<Item> ptrCopy1 = ptr;

	{
		shared_ptr<Item> ptrCopy2 = ptr;
		cout << "counter: " << ptr.use_count() << endl;
	}

	cout << "counter: " << ptr.use_count() << endl;


	shared_ptr<Item> ptr2(new Item);
	cout << "counter: " << ptr2.use_count() << endl;

}


class Human
{
	string m_name;
	weak_ptr<Human> m_partner; // обратите внимание, здесь std::weak_ptr

public:

	Human(const string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Human()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(shared_ptr<Human>& h1, shared_ptr<Human>& h2)
	{
		if (!h1 || !h2)
			return false;

		h1->m_partner = h2;
		h2->m_partner = h1;

		cout << h1->m_name << " is now partnered with " << h2->m_name << "\n";

		return true;
	}
};


void UsingWeakPtr() 
{
	auto anton = make_shared<Human>("Anton");
	auto ivan =  make_shared<Human>("Ivan");	

	partnerUp(anton, ivan);
}

int main()
{
	//auto_ptr<Item> ptr;

    //UsingUniquePtr();
	//UsingSharedPtr();
	UsingWeakPtr();
	
	int* p = nullptr;
	delete[] p;
}