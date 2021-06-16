#pragma once

class Fraction
{
public:

	Fraction() = default;
	explicit Fraction(int numerator, int denominator = 1);

	void Print();

	int GetNumerator() const;
	int GetDenominator() const;

	Fraction operator/ (const Fraction& fraction);
	Fraction operator/ (int num);

private:
	int numerator_ = 0; //числитель
	int denominator_ = 1; //знаминатель
};

Fraction operator*(const Fraction& leftOperand, const Fraction& rightOperand);
Fraction operator*(const Fraction& leftOperand, int rightOperand);
Fraction operator*(int leftOperand, const Fraction& rightOperand);

Fraction operator/(int leftOperand, const Fraction& rightOperand);


