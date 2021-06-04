#include <iostream>
#include <cstring>
#include <Windows.h> //��� ��������� COORD
using namespace std;

#include "Point.h"

class Character {

private: //�������� ������ ������ ������

	char name_[100];
	unsigned lifes_;
	COORD coord_; //��������� � ���� ������ X, y 

public: //�������� �����

	void SetName(const char* name)
	{
		strcpy_s(name_, 100, name);
	}

	void SetLifes(int lifes)
	{
		lifes_ = lifes;
	}

	void SetCoords(short x, short y) 
	{
		coord_.X = x;
		coord_.Y = y;
	}

	void PrintInfo()
	{
		cout << endl;
		cout << "Name: " << name_ << endl;
		cout << "Lifes: " << lifes_ << endl;
		cout << "Coords: " << coord_.X << ", " << coord_.Y << endl;		
	}

	void MoveRight() 
	{
		coord_.X++;
	}

	void MoveLeft()
	{
		coord_.X--;
	}

};


int main()
{
	Point p1; //������ ������ Point

	p1.x_ = 0; //��������� � ����
	p1.y_ = 0;

	p1.Print(); //��������� � ������

	//Print(); //error

	Character mario;
	mario.SetName("Mario");
	mario.SetLifes(3);
	mario.SetCoords(0, 0);	

	mario.PrintInfo();

	mario.MoveRight();
	mario.PrintInfo();

	//mario.coord.X = -100; //������������������� ���������
}