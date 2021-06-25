#pragma once

#include "Header.h"

class Student
{
public:

	Student(string firstname, string lastname, string phone = "+");
	~Student() { count--; }

	void SetFirstname(string firstname);
	void SetLastname(string lastname);
	void SetPhone(string phone);

	string GetFirstname() { return _firstname; }
	string GetLastname() { return _lastname; }
	string GetPhone() { return _phone; }

	static bool IsValidString(string str, string symbols);

	static int GetCount() { return count; }
private:
	int _number;
	string _firstname;
	string _lastname;
	string _phone;
	double _rate = 0;

	static string symbols;
	static int lastNumber;
	static int count;

	
};

