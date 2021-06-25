#include "Header.h"

string Student::symbols = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
int Student::lastNumber = 0;
int Student::count = 0;

Student::Student(string firstname, string lastname, string phone)
{
	count++;

	_number = ++lastNumber;

	SetFirstname(firstname);
	SetLastname(lastname);
	SetPhone(phone);
}

void Student::SetFirstname(string firstname)
{
	if (!IsValidString(firstname, symbols))
	{
		cerr  << "Error!";
		return;
	}
	_firstname = firstname;
}

void Student::SetLastname(string lastname)
{
	if (!IsValidString(lastname, symbols))
	{
		cerr << "Error!";
		return;
	}
	_lastname = lastname;

}

void Student::SetPhone(string phone)
{
	string symbols = "+()0123456789-";

	if (!IsValidString(phone, symbols))
	{
		cerr << "Error!";
		return;
	}

	_phone = phone;
}

bool Student::IsValidString(string str, string symbols)
{
	return !str.empty() && str.find_first_not_of(symbols) == string::npos;
}
