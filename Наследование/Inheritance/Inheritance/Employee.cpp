#include "Headers.h"

Employee::Employee()
{
	cout << "Employee constructor " << endl;

	_firstname = "undefined";
	_lastname = "undefined";
	_phone = "undefined";
	_salary = 0;
}

Employee::Employee(string firstname, string lastname, double sallary, string phone)
{
	cout << "Employee constructor with params" << endl;

	SetFirstname(firstname);
	SetLastname(lastname);
	SetPhone(phone);
	SetSalary(sallary);
}

Employee::Employee(const Employee& source)
{
	cout << "Employee constructor copy" << endl;

	_firstname = source._firstname;
	_lastname = source._lastname;
	_phone = source._phone;
	_salary = source._salary;
}

Employee::~Employee()
{
	cout << "Employee destructor " << endl;
}

void Employee::SetFirstname(string firstname)
{
	if (firstname.size() == 0)
	{
		cerr << "Error: firstname is empty" << endl;
		return;
	}

	_firstname = firstname;
}

void Employee::SetLastname(string lastname)
{
	if (lastname.size() == 0)
	{
		cerr << "Error: lastname is empty" << endl;
		return;
	}

	_lastname = lastname;
}

void Employee::SetPhone(string phone)
{
	if (phone.size() == 0)
	{
		cerr << "Error: phone is empty" << endl;
		return;
	}
	_phone = phone;
}

void Employee::SetSalary(double sallary)
{
	_salary = sallary;
}

void Employee::Print()
{
	cout << "Fullname:\t" << _firstname << " " << _lastname << endl;
	cout << "Phone:\t\t" << _phone << endl;
	cout << "Sallary:\t" << _salary << endl;
}
