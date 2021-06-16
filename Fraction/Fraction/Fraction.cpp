#include <iostream>
using namespace std;

#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
    numerator_ = numerator;
    denominator_ = denominator;
}

void Fraction::Print()
{
    cout << numerator_ << " / " << denominator_ << endl;
}

int Fraction::GetNumerator() const
{
    return numerator_;
}

int Fraction::GetDenominator() const
{
    return denominator_;
}

Fraction Fraction::operator/(const Fraction& rightOperand)
{
    Fraction result;
    result.numerator_ = this->numerator_ * rightOperand.denominator_;
    result.denominator_ = denominator_ * rightOperand.numerator_;

    return result;
}

Fraction Fraction::operator/(int num)
{
    Fraction result;
    result.numerator_ = numerator_;
    result.denominator_ = denominator_ * num;
    return result;
}

//function

Fraction operator*(const Fraction& leftOperand, const Fraction& rightOperand)
{
    Fraction result(
        leftOperand.GetNumerator() * rightOperand.GetNumerator(),
        leftOperand.GetDenominator() * rightOperand.GetDenominator()
     );
    
    return result;
}

Fraction operator*(const Fraction& leftOperand, int rightOperand)
{
    Fraction result(
        leftOperand.GetNumerator() * rightOperand,
        leftOperand.GetDenominator());

    return result;
}

Fraction operator*(int leftOperand, const Fraction& rightOperand)
{
    Fraction result(
        leftOperand * rightOperand.GetNumerator(),
        rightOperand.GetDenominator());

    return result;
}

Fraction operator/(int leftOperand, const Fraction& rightOperand)
{
    Fraction result(
        leftOperand * rightOperand.GetDenominator(),
        rightOperand.GetNumerator());

    return result;
}
