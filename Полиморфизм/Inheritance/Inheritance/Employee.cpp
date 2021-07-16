#include "Headers.h"

Employee::Employee()
{
#ifdef DEBUG
	cout << "Employee constructor " << endl;
#endif

	_firstname = "undefined";
	_lastname = "undefined";
	_phone = "undefined";
	_sallary = 0;
}

Employee::Employee(string firstname, string lastname, double sallary, string phone)
{
#ifdef DEBUG
	cout << "Employee constructor with params" << endl;
#endif

	SetFirstname(firstname);
	SetLastname(lastname);
	SetPhone(phone);
	SetSallary(sallary);
}

Employee::Employee(const Employee& source)
{
#ifdef DEBUG
	cout << "Employee constructor copy" << endl;
#endif

	_firstname = source._firstname;
	_lastname = source._lastname;
	_phone = source._phone;
	_sallary = source._sallary;
}

Employee::~Employee()
{
#ifdef DEBUG
	cout << "Employee destructor " << endl;
#endif
	
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

void Employee::SetSallary(double sallary)
{
	_sallary = sallary;
}

void Employee::Print()
{
	cout << "Fullname:\t" << _firstname << " " << _lastname << endl;
	cout << "Phone:\t\t" << _phone << endl;
	cout << "Sallary:\t" << _sallary << endl;
}
