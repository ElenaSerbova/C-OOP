#include "Headers.h"

Сashier::Сashier() : Employee("undefined", "undefined", 0)
{
#ifdef DEBUG
	cout << "Cashier constructor" << endl;
#endif

	_login = "undefined";
	_password = "undefined";
}

Сashier::~Сashier()
{
#ifdef DEBUG
	cout << "Cashier destructor" << endl;
#endif
}

void Сashier::SetAuthInfo(string login, string password)
{
	_login = login;
	_password = password;
}

bool Сashier::CheckAuthInfo(string login, string password)
{
	return login == _login && password == _password;
}

void Сashier::Print()
{
	cout << "Cashier: " << endl;
	Employee::Print();
	cout << "login: " << _login << endl;
}
