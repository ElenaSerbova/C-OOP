#include "Time.h"

#include <iostream>
using namespace std;

Time::Time(int hours, int minutes, int seconds)
	: hours_(hours), minutes_(minutes), seconds_(seconds)
{
}

Time::Time() : Time(0, 0, 0)
{	
}

Time::Time(int hours, int minutes) : Time(hours, minutes, 0)
{
}

Time::Time(int hours) : Time(hours, 0, 0)
{	
}

void Time::SetHours(int hours)
{
	if (hours >= 0 && hours <= 23)
	{
		hours_ = hours;
	}
	else
	{
		hours_ = 0;
		cout << "Error" << endl;
	}
}

void Time::SetMinutes(int minutes)
{
	if (minutes >= 0 && minutes <= 59)
	{
		minutes_ = minutes;
	}
	else
	{
		minutes_ = 0;
		cout << "Error" << endl;
	}
}

void Time::SetSeconds(int seconds)
{
	if (seconds >= 0 && seconds <= 59)
	{
		seconds_ = seconds;
	}
	else
	{
		seconds_ = 0;
		cout << "Error" << endl;
	}
}

int Time::GetHours()
{
	return hours_;
}

int Time::GetMinutes()
{
	return minutes_;
}

int Time::GetSeconds()
{
	return seconds_;
}
