#include "Fraction.h"

double Fraction::result(int numerator_, int denominator_) { 
	return static_cast<double>(numerator_) / denominator_; 
}

bool Fraction::operator==(Fraction& fraction) {
	if (result(numerator_, denominator_) == result(fraction.numerator_, fraction.denominator_)) {
		return true;
	}
	else {
		return false;
	}
}

bool Fraction::operator!=(Fraction& fraction) {
	if (!(*this == fraction)) {
		return true;
	}
	else {
		return false;
	}
}

bool Fraction::operator<(Fraction& fraction) {
	if (result(numerator_, denominator_) < result(fraction.numerator_, fraction.denominator_)) {
		return true;
	}
	else {
		return false;
	}
}

bool Fraction::operator>(Fraction& fraction) {
	if (result(numerator_, denominator_) > result(fraction.numerator_, fraction.denominator_)) {
		return true;
	}
	else {
		return false;
	}
}

bool Fraction::operator<=(Fraction& fraction) {
	if (result(numerator_, denominator_) <= result(fraction.numerator_, fraction.denominator_)) {
		return true;
	}
	else {
		return false;
	}
}

bool Fraction::operator>=(Fraction& fraction) {
	if (result(numerator_, denominator_) >= result(fraction.numerator_, fraction.denominator_)) {
		return true;
	}
	else {
		return false;
	}
}

double Fraction::NOD(int numerator_, int denominator_) {
	int div;
	if (numerator_ == denominator_)  return numerator_;
	int d = numerator_ - denominator_;
	if (d < 0) {
		d = -d;  div = NOD(numerator_, d);
	}
	else
		div = NOD(denominator_, d);
	return div;
}
double Fraction::NOK(int numerator_, int denominator_) {
		return numerator_ * denominator_ / NOD(numerator_, denominator_);
	}


std::ostream& operator<<(std::ostream& left, Fraction& right) {
	left << right.numerator_ << "/" << right.denominator_ << std::endl;
	return left;
}

Fraction Fraction::operator+(Fraction& fraction) {
	int new_denominator_ = denominator_ * fraction.denominator_;
	int new_numerator_ = new_denominator_ / denominator_ * numerator_ + new_denominator_ / fraction.denominator_ * fraction.numerator_;
	double nod = NOD(abs(new_numerator_), abs(new_denominator_));
	if ( nod != 1) {
		new_denominator_ /= nod;
		new_numerator_ /= nod;

	}
	return Fraction(new_numerator_, new_denominator_);
}

Fraction Fraction::operator-(Fraction& fraction) {
	int new_denominator_ = denominator_ * fraction.denominator_;
	int new_numerator_ = new_denominator_ / denominator_ * numerator_ - new_denominator_ / fraction.denominator_ * fraction.numerator_;
	double nod = NOD(abs(new_numerator_), abs(new_denominator_));
	if (nod != 1) {
		new_denominator_ /= nod;
		new_numerator_ /= nod;

	}
	return Fraction(new_numerator_, new_denominator_);
}

Fraction Fraction::operator*(Fraction& fraction) {
	int new_denominator_ = denominator_ * fraction.denominator_;
	int new_numerator_ = numerator_  * fraction.numerator_;
	double nod = NOD(abs(new_numerator_), abs(new_denominator_));
	if (nod != 1) {
		new_denominator_ /= nod;
		new_numerator_ /= nod;

	}
	return Fraction(new_numerator_, new_denominator_);
}

Fraction Fraction::operator/(Fraction& fraction) {
	int new_denominator_ = denominator_ * fraction.numerator_;
	int new_numerator_ = numerator_ * fraction.denominator_;
	double nod = NOD(abs(new_numerator_), abs(new_denominator_));
	if (nod != 1) {
		new_denominator_ /= nod;
		new_numerator_ /= nod;

	}
	return Fraction(new_numerator_, new_denominator_);
}

Fraction& Fraction::operator++() {
	double f = result(numerator_, denominator_);
	f++;
	numerator_ = f * denominator_;
	double nod = NOD(abs(numerator_), abs(denominator_));
	if (nod != 1) {
		numerator_ /= nod;
		denominator_ /= nod;

	}
	return *this;
}
Fraction Fraction::operator++(int) {
	Fraction temp = *this;
	++(*this);
	return temp;
}
Fraction& Fraction::operator--() {
	double f = result(numerator_, denominator_);
	f--;
	numerator_ = f * denominator_;
	double nod = NOD(abs(numerator_), abs(denominator_));
	if (nod != 1) {
		numerator_ /= nod;
		denominator_ /= nod;

	}
	return *this;
}
Fraction Fraction::operator--(int) {
	Fraction temp = *this;
	--(*this);
	return temp;
}