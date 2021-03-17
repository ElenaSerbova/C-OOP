#pragma once

#include <iostream>
using namespace std;

class Point
{
	int _x;
	int _y;

public:
	Point(int x, int y);

	int getX() { return _x; }
	int getY() { return _y; }

	friend ostream& operator<< (ostream& stream, const Point& p)
	{
		stream << "{ " << p._x << ", " << p._y << " }";
		return stream;
	}
	
};

