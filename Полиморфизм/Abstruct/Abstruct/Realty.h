#pragma once

#include "Header.h"

//abstract class
class Realty //Недвижимость
{
public:
	string address;
	double square;

	virtual void Print();

	virtual double GetCost() = 0; //abstract method - pure virtual function

	virtual ~Realty() = 0 {};

};

