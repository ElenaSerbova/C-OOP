#pragma once

#include "Headers.h"

class Employee
{
public:

	Employee();
	Employee(string firstname, string lastname, double salary, string phone = "undefined");

	Employee(const Employee& source);

	~Employee();

	void SetFirstname(string firstname);
	void SetLastname(string lastname);
	void SetPhone(string phone);
	void SetSalary(double sallary);

	string GetFirstname() { return _firstname; }
	string GetLastname() { return _lastname; }
	string GetPhone() { return _phone; }
	double GetSalary() { return _salary; }

	void Print();

private:
	string _firstname;
	string _lastname;
	string _phone;
	double _salary;
};

