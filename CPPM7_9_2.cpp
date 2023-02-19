#include "CPPM7_9_2.h"

void CPPM7_9_2()
{
	int numerator_1, denominator_1, numerator_2, denominator_2;
	std::cout << "¬ведите числитель дроби 1: ";
	std::cin >> numerator_1;
	std::cout << "¬ведите знаменатель дроби 1: ";
	std::cin >> denominator_1;
	std::cout << "¬ведите числитель дроби 2: ";
	std::cin >> numerator_2;
	std::cout << "¬ведите знаменатель дроби 2: ";
	std::cin >> denominator_2;
	Fraction f1(numerator_1, denominator_1), f2(numerator_2, denominator_2), f3(0, 0);
	f3 = f1 + f2;
	std::cout << numerator_1 << "/" << denominator_1 << " + " << numerator_2 << "/" << denominator_2 << " = " << f3;
	f3 = f1 - f2;
	std::cout << numerator_1 << "/" << denominator_1 << " - " << numerator_2 << "/" << denominator_2 << " = " << f3;
	f3 = f1 * f2;
	std::cout << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << f3;
	f3 = f1 / f2;
	std::cout << numerator_1 << "/" << denominator_1 << " / " << numerator_2 << "/" << denominator_2 << " = " << f3;
	f3 = ++f1 * f2;
	std::cout << "++" << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << f3;
	std::cout << "«начение дроби 1 = " << f1;
	std::cout << f1.get_numerator_() << "/" << f1.get_denominator_() << "--" << " * " << numerator_2 << "/" << denominator_2 << " = ";
	f3 = f1-- * f2;
	std::cout << f3;
	std::cout << "«начение дроби 1 = " << f1;
}
