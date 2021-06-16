#include <iostream>
#include "SuperHero.h"
using namespace std;

int main()
{
    SuperHero hero1("IronMan", "Tony Stark");
    hero1.Print();

    SuperHero hero2("", "");

    hero2.Copy(hero1);
    hero2.Print();

    hero2.~SuperHero();
}