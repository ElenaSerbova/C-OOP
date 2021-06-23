#include <iostream>
#include "SuperHero.h"
#include "League.h"
using namespace std;

int main()
{
    League league;

    char hero_name[50];
    cout << "Enter hero name: ";
    cin.getline(hero_name, 50);

    char* alter_ego = league[hero_name];
    if (alter_ego == nullptr)
    {
        cout << "Hero not found" << endl;
    }
    else 
    {
        cout << "Alter ego: " << alter_ego << endl;
    }

    SuperHero hero = league[0];
    hero.Print();

}