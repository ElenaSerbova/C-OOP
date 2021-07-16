#pragma once

#include "Headers.h"

class Employee
{
public:

	Employee();
	Employee(string firstname, string lastname, double sallary, string phone = "undefined");

	Employee(const Employee& source);

	~Employee();

	void SetFirstname(string firstname);
	void SetLastname(string lastname);
	void SetPhone(string phone);
	void SetSallary(double sallary);

	string GetFirstname() { return _firstname; }
	string GetLastname() { return _lastname; }
	string GetPhone() { return _phone; }
	double GetSallary() { return _sallary; }

	virtual void Print();

private:
	string _firstname;
	string _lastname;
	string _phone;
	double _sallary;
};

