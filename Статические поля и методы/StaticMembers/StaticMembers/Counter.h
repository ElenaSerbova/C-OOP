#pragma once
#include <iostream>
using namespace std;

class Counter
{
public:

	Counter()
	{
		count++;
	}

	~Counter()
	{
		count--;
	}

	static int GetCount()
	{		
		return count;
	}

private:

	static int count;
	int a;
};

int Counter::count;

