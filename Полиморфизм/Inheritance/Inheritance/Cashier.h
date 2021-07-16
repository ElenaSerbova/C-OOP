#pragma once

#include "Headers.h"

class Сashier :  public Employee
{
public:

	Сashier();
	Сashier(string firstname, string lastname, double sallary) 
		: Employee(firstname, lastname, sallary) {}
	
	~Сashier();

	void SetAuthInfo(string login, string password);
	bool CheckAuthInfo(string login, string password);

	virtual void Print() ;

private:
	string _login;
	string _password;
};

