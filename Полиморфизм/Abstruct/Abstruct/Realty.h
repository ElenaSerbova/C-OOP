#pragma once

#include "Header.h"

//abstruct class
class Realty //Недвижимость
{
public:
	string address;
	double square;

	virtual void Print();

	virtual double GetCost() = 0; //abstruct method - pure virtual function

	virtual ~Realty() = 0 {};

};

