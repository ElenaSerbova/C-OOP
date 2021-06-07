#pragma once

class Time
{
public:
	//Constructors

	Time(); //Default constructor
	Time(int hours, int minutes, int seconds);
	Time(int hours, int minutes);
	Time(int hours);
	

	//Accessors - функции доступа
	
	//modificators
	void SetHours(int hours);
	void SetMinutes(int minutes);
	void SetSeconds(int seconds);

	//inspectors
	int GetHours();
	int GetMinutes();
	int GetSeconds();

private:
	int hours_ = 0;
	int minutes_ = 0;
	int seconds_ = 0;
};

