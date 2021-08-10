#include "Header.h"

int main()
{
    Realty* realty = new Apartment();
    double cost = realty->GetCost();
    
    delete realty; //realty->destructor();

  
}

