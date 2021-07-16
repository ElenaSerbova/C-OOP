#pragma once
#include"Header.h"

class House :
    public Realty
{
public:
    double floorCount = 1;

    virtual void Print() override;

    virtual double GetCost() override;
};

