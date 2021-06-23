#include <iostream>
using namespace std;

int foo()
{
	int i = 100;
	return i; //1. copy, 2. delete
}

int main()
{
	// l-value Ч это значение, которое имеет свой собственный адрес в пам€ти.

	//например переменна€
	int a = 10;
	cout << "address a: "<< &a << endl;	

	//или константа
	const int c = 10;
	cout << "address c: "<< &c << endl;	

	// r-value Ч это значение, которое не имеет посто€нного адреса в пам€ти

	//например литералы, 
	//временные объекты, которые создаютс€ при возврате из функций и операций

	// Error: cout << "address literal: " << &123 << endl;
	
	//ƒо версии C++11 существовал только один тип ссылок, его называли просто Ч Ђссылкаї.
	//¬ C++11 этот тип ссылки еще называют Ђссылкой l-valueї.
	//≈е можно создать только на l-value значение
	
	int& ra = a; 
	const int& rc = c;	
	// Error: int& rl = 123;

	//¬ C++11 добавили новый тип ссылок Ч ссылки r-value.
	//это ссылки, которые инициализируютс€ только значени€ми r-values.

	int&& rl = 123; 	
	int&& rfoo = foo();
	int&& rop = 2 + 3;	

	cout << rl << endl;
	cout << rfoo << endl;
	cout << rop << endl;
}
