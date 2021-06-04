#include "Point.h"

#include <iostream>
using namespace std;

//определение метода вне класса
void Point::Print() //обязательно указать имя класса
{
	cout << "x: " << x_ << ", y: " << y_ << endl;
}