#include "Time.h"
#include <iostream>
#include <time.h>
using namespace std;

Time::Time(int hours, int minutes, int seconds)
{
	SetHours(hours);
	SetMinutes(minutes);
	SetSeconds(seconds);
}

void Time::SetHours(int hours)
{
	if (hours < 0 || hours > 23)
	{
		cerr << "Error: hours must be between 0 and 23" << endl;
		_hours = 0;
	}
	else
	{
		_hours = hours;
	}
}

void Time::SetMinutes(int minutes)
{
	if (minutes < 0 || minutes > 59)
	{
		cerr << "Error: hours minutes be between 0 and 59" << endl;
		_minutes = 0;
	}
	else
	{
		_minutes = minutes;
	}
}

void Time::SetSeconds(int seconds)
{
	if (seconds < 0 || seconds > 59)
	{
		cerr << "Error: hours seconds be between 0 and 59" << endl;
		_seconds = 0;
	}
	else
	{
		_seconds = seconds;
	}
}

int Time::GetHours()
{
	return _hours;
}

int Time::GetMinutes()
{
	return _minutes;
}

int Time::GetSeconds()
{
	return _seconds;
}

Time Time::GetCurrentTime()
{
	time_t t = time(0); //получаем метку времени
	tm tm;
	localtime_s(&tm, &t); //заполняем структуру tm, датой и временем из метки времени

	return Time(tm.tm_hour, tm.tm_min, tm.tm_sec);
}
