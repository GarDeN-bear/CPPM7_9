#pragma once
#include <iostream>
class Fraction
{
private:
	int numerator_;
	int denominator_;
	double result(int numerator_, int denominator_);
	// Наибольший общий делитель
	double NOD(int numerator_, int denominator_);
	// Наименьшее общее кратное
	double NOK(int numerator_, int denominator_);
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	int get_numerator_() {
		return numerator_;
	}

	int get_denominator_() {
		return denominator_;
	}

	bool operator==(Fraction& fraction);
	bool operator!=(Fraction& fraction);
	bool operator<(Fraction& fraction);
	bool operator>(Fraction& fraction);
	bool operator<=(Fraction& fraction);
	bool operator>=(Fraction& fraction);

	friend std::ostream& operator<<(std::ostream& left, Fraction& right);

	Fraction operator+(Fraction& fraction);
	Fraction operator-(Fraction& fraction);
	Fraction operator*(Fraction& fraction);
	Fraction operator/(Fraction& fraction);
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
};