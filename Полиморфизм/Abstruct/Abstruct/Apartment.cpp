#include "Header.h"

void Apartment::Print()
{
	Realty::Print();
	cout << "Rooms: " << roomCount << endl;	
}

double Apartment::GetCost()
{
	return roomCount * 100;
}
