#pragma once

#include <iostream>
using namespace std;

class Fraction
{
	friend Fraction operator*(Fraction leftOp, Fraction rightOp);
	friend Fraction operator*(Fraction leftOp, int rightOp);
	friend Fraction operator*(int leftOp, Fraction rightOp);

public:

#pragma region Constructors
	Fraction() = default;
	explicit Fraction(int numerator);
	Fraction(int numerator, int denominator);
#pragma endregion

#pragma region Accessors
	int GetNumerator() const {		
		return this->_numerator; 
	}
	int GetDenominator() const { 
		return this->_denominator; 
	}	

	void SetNumerator(int numerator);
	void SetDenominator(int denominator);
#pragma endregion
	
#pragma region operator/

	Fraction operator/ (Fraction rightOp);
	Fraction operator/ (int rightOp);
	friend Fraction operator/(int leftOp, Fraction rightOp);

#pragma endregion

#pragma region decrement

	Fraction operator--();
	Fraction operator--(int);

#pragma endregion

#pragma region Conversion

	explicit operator double();
	explicit operator int();
#pragma endregion

private:
	int _numerator = 0; //числитель
	int _denominator = 1; //знаменатель

};

#pragma region operator*

Fraction operator*(Fraction leftOp, Fraction rightOp);
Fraction operator*(Fraction leftOp, int rightOp);
Fraction operator*(int leftOp, Fraction rightOp);

#pragma endregion


#pragma region unary operator-

Fraction operator-(Fraction fr);

#pragma endregion

#pragma region increment

Fraction operator++(Fraction& fr);
Fraction operator++(Fraction& fr, int);

#pragma endregion

#pragma region equals

bool operator== (Fraction leftOp, Fraction rightOp);
bool operator!= (Fraction leftOp, Fraction rightOp);

#pragma endregion

