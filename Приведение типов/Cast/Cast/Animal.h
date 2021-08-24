#pragma once

#include <iostream>
#include <string>
using namespace std;


class Animal
{
public:

	virtual void Print()
	{
		cout << "Animal" << endl;
	}

};

class Bird : public Animal
{
	int field = 0;
public:

	virtual void Print() override 
	{
		cout << "Bird" << endl;
	}

	void ChikChirik()
	{
		field = 10;
		cout << "ChikChirik" << endl;
	}
};

class Cat : public Animal
{
public:

	virtual void Print() override
	{
		cout << "Cat" << endl;
	}

	void Meow() {
		cout << "Meow" << endl;
	}
};

