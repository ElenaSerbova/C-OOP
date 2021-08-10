#pragma once
#include "Header.h"


class Apartment :
    public Realty
{
private:
    int roomCount = 1;

    double* squareRooms = nullptr;
   

public:

    Apartment(int rooms = 1)
    {
        squareRooms = new double[rooms];

        for (size_t i = 0; i < rooms; i++)
        {
            squareRooms[i] = 1;
        }
        roomCount = rooms;
    }

    ~Apartment()
    {
        delete[] squareRooms;
    }

    Apartment(const Apartment& a) = delete;
    Apartment& operator= (const Apartment& a) = delete;

    Apartment(Apartment&& a) = delete;
    Apartment& operator= (Apartment&& a) = delete;

    virtual void Print() override;

    virtual double GetCost() override;
};

