#include "Header.h"

void House::Print()
{
	Realty::Print();
	cout << "Floors: " << floorCount << endl;
}

double House::GetCost()
{
	return floorCount * 100;
}
