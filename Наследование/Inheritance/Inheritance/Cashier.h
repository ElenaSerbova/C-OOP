#pragma once

#include "Headers.h"

class Сashier :  public Employee
{
public:

	Сashier();
	~Сashier();

	void SetAuthInfo(string login, string password);
	bool CheckAuthInfo(string login, string password);

	void Print();

private:
	string _login;
	string _password;
};

