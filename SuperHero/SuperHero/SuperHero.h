#pragma once

#include <cstring>
#include <iostream>
using namespace std;

class SuperHero
{
public:
	
	SuperHero() = default;
	SuperHero(const char* heroName, const char* alterEgo)
	{
		int length = strlen(heroName);
		heroName_ = new char[length + 1];
		strcpy_s(heroName_, length + 1, heroName);

		length = strlen(alterEgo);
		alterEgo_ = new char[length + 1];
		strcpy_s(alterEgo_, length + 1, alterEgo);
	}

	SuperHero(const SuperHero& hero)
	{
		Copy(hero);
	}

	SuperHero& operator=(const SuperHero& hero) 
	{
		if (this != &hero) 
		{
			Clear();
			Copy(hero);
		}

		return *this;
	}

	~SuperHero()
	{
		Clear();
	}

	void Print() 
	{
		cout << "Hero name: " << heroName_ << endl;
		cout << "Alter ego: " << alterEgo_ << endl;
	}

	void Copy(const SuperHero& hero)
	{
		int length = strlen(hero.heroName_);
		heroName_ = new char[length + 1];
		strcpy_s(heroName_, length + 1, hero.heroName_);

		length = strlen(hero.alterEgo_);
		alterEgo_ = new char[length + 1];
		strcpy_s(alterEgo_, length + 1, hero.alterEgo_);
	}

	void Clear()
	{
		if (heroName_ != nullptr)
		{
			delete[] heroName_;
			heroName_ = nullptr;
		}

		if (alterEgo_ != nullptr)
		{
			delete[] alterEgo_;
			alterEgo_ = nullptr;
		}
	}

	char* GetHeroName() {
		return heroName_;
	}

	char* GetAlterEgo() {
		return alterEgo_;
	}

private:
	char* heroName_ = nullptr;
	char* alterEgo_ = nullptr;
};

