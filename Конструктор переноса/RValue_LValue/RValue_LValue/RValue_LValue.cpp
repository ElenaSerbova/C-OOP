#include <iostream>
using namespace std;

int foo()
{
	int i = 100;
	return i; //1. copy, 2. delete
}

int main()
{
	// l-value � ��� ��������, ������� ����� ���� ����������� ����� � ������.

	//�������� ����������
	int a = 10;
	cout << "address a: "<< &a << endl;	

	//��� ���������
	const int c = 10;
	cout << "address c: "<< &c << endl;	

	// r-value � ��� ��������, ������� �� ����� ����������� ������ � ������

	//�������� ��������, 
	//��������� �������, ������� ��������� ��� �������� �� ������� � ��������

	// Error: cout << "address literal: " << &123 << endl;
	
	//�� ������ C++11 ����������� ������ ���� ��� ������, ��� �������� ������ � �������.
	//� C++11 ���� ��� ������ ��� �������� �������� l-value�.
	//�� ����� ������� ������ �� l-value ��������
	
	int& ra = a; 
	const int& rc = c;	
	// Error: int& rl = 123;

	//� C++11 �������� ����� ��� ������ � ������ r-value.
	//��� ������, ������� ���������������� ������ ���������� r-values.

	int&& rl = 123; 	
	int&& rfoo = foo();
	int&& rop = 2 + 3;	

	cout << rl << endl;
	cout << rfoo << endl;
	cout << rop << endl;
}
