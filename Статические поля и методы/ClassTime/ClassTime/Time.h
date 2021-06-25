#pragma once

class Time
{
public:	
	Time(int hours = 0, int minutes = 0, int seconds = 0);

	void SetHours(int hours);
	void SetMinutes(int minutes);
	void SetSeconds(int seconds);

	int GetHours();
	int GetMinutes();
	int GetSeconds();

	static Time GetCurrentTime();

private:
	int _hours;
	int _minutes;
	int _seconds;	
};

