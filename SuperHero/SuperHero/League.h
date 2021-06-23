#pragma once

#include <cstring>

#include "SuperHero.h"

class League
{
public:
	League() 
	{
		size_ = 5;
		heroes_ = new SuperHero[size_]{
			SuperHero("Ironman", "Tony Stark"),
			SuperHero("Spiderman", "Piter Parker"),
			SuperHero("Batman", "Bruce Wayne"),
			SuperHero("Karlson", "Karl Son"),
			SuperHero("Wonder woman", "Linda Karter")
		};
	}

	char* operator[](const char* hero_name) 
	{
		for (size_t i = 0; i < size_; i++)
		{
			if ( _stricmp(heroes_[i].GetHeroName(), hero_name) == 0 )
			{
				return heroes_[i].GetAlterEgo();
			}
		}

		return nullptr;
	}

	SuperHero& operator[](int i)
	{
		return heroes_[i];
	}

private:
	SuperHero* heroes_ = nullptr;
	size_t size_ = 0;
};

