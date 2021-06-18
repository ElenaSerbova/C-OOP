#include "Fraction.h"

#pragma region Constructors
Fraction::Fraction(int numerator)
{
	_numerator = numerator;
}

Fraction::Fraction(int numerator, int denominator) : Fraction(numerator)
{	
	if (denominator != 0)
	{
		_denominator = denominator;
	}
}

#pragma endregion

#pragma region Accessors
void Fraction::SetNumerator(int numerator)
{
	_numerator = numerator;
}

void Fraction::SetDenominator(int denominator)
{
	if (denominator != 0)
	{
		_denominator = denominator;
	}
}

#pragma endregion
#pragma region operator/

Fraction Fraction::operator/(Fraction rightOp)
{
	if (rightOp._numerator != 0)
	{
		int resNumerator = this->_numerator * rightOp._denominator;
		int resDenominator = this->_denominator * rightOp._numerator;

		Fraction result(resNumerator, resDenominator);
		//сокращение дроби result
		return result;
	}
	else
	{
		cout << "Error" << endl;
		return Fraction();
	}
}

Fraction Fraction::operator/(int rightOp)
{
	int resNumerator = _numerator;
	int resDenominator = _denominator * rightOp;

	Fraction result(resNumerator, resDenominator);
	//сокращение дроби result
	return result;
}

Fraction& Fraction::operator*=(const Fraction& rightOp)
{
	_numerator *= rightOp._numerator;
	_denominator *= rightOp._denominator;
	
	return *this;
}

Fraction& Fraction::operator*=(int rightOp)
{
	_numerator *= rightOp;
	return *this;
}

Fraction operator/(int leftOp, Fraction rightOp)
{
	int resNumerator = leftOp * rightOp.GetDenominator();
	int resDenominator = rightOp.GetNumerator();

	Fraction result(resNumerator, resDenominator);
	//сокращение дроби result
	return result;
}

#pragma endregion

#pragma region operator*

Fraction operator*(Fraction leftOp, Fraction rightOp)
{
	int resNumerator = leftOp.GetNumerator() * rightOp.GetNumerator();
	int resDenominator = leftOp.GetDenominator() * rightOp.GetDenominator();

	Fraction result(resNumerator, resDenominator);
	//сокращение дроби result
	return result;
}

Fraction operator*(Fraction leftOp, int rightOp)
{
	int resNumerator = leftOp.GetNumerator() * rightOp;
	int resDenominator = leftOp.GetDenominator();

	Fraction result(resNumerator, resDenominator);
	//сокращение дроби result
	return result;
}

Fraction operator*(int leftOp, Fraction rightOp)
{
	int resNumerator = leftOp * rightOp.GetNumerator();
	int resDenominator = rightOp.GetDenominator();

	Fraction result(resNumerator, resDenominator);
	//сокращение дроби result
	return result;
}

#pragma endregion

#pragma region unary operator-

Fraction operator-(Fraction fr)
{
	int resNumerator = -fr.GetNumerator();
	int resDenominator = fr.GetDenominator();

	return Fraction(resNumerator, resDenominator);
}

#pragma endregion

#pragma region increment

Fraction operator++(Fraction& fr)
{
	int resNumerator = fr.GetNumerator() + fr.GetDenominator();	
	fr.SetNumerator(resNumerator);

	return fr;
}

Fraction operator++(Fraction& fr, int)
{
	Fraction oldValue = fr;
	
	int resNumerator = fr.GetNumerator() + fr.GetDenominator();
	fr.SetNumerator(resNumerator);

	return oldValue;
}

#pragma endregion

#pragma region decrement

Fraction Fraction::operator--()
{
	_numerator -= _denominator;

	return *this; //return fr;
}

Fraction Fraction::operator--(int)
{
	Fraction oldValue = *this;

	_numerator -= _denominator;

	return oldValue;
}

#pragma endregion

#pragma region equals

bool operator==(Fraction leftOp, Fraction rightOp)
{
	//сокращение обеих дробей 
	return leftOp.GetNumerator() == rightOp.GetNumerator() && 
		leftOp.GetDenominator() == rightOp.GetDenominator();
}

bool operator!=(Fraction leftOp, Fraction rightOp)
{
	return !(leftOp == rightOp);
}

#pragma endregion

