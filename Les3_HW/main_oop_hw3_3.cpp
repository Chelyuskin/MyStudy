#include <iostream>

/*

Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).

Предусмотреть, чтобы знаменатель не был равен 0.

Перегрузить: математические бинарные операторы (+, -, *, /) для выполнения действий с дробями.

унарный оператор (-).

логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).

Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.

Продемонстрировать использование перегруженных операторов.

*/

class Fraction
{
private:
	double _numerator = 0;
	double _denominator = 0;

public:
	Fraction() {}

	Fraction(int numerator, int denominator)
		:_numerator(numerator), _denominator(denominator)
	{

		if (_denominator == 0)

		{
			std::cout << "Error! The denominator cannot be zero" << std::endl;
		}
	}

	Fraction operator+(const Fraction& other) const

	{
		Fraction tempAdd;
		Fraction tempAdd1;
		if (_denominator != other._denominator)
		{
			tempAdd._denominator = _denominator * other._denominator;
			tempAdd._numerator = _numerator * other._denominator;
			tempAdd1._numerator = _denominator * other._numerator;
			tempAdd._numerator = tempAdd._numerator + tempAdd1._numerator;
		}
		else
		{
			tempAdd._numerator = _numerator + other._numerator;
			tempAdd._denominator = _denominator;
		}
		return tempAdd;
	}

	Fraction operator-(const Fraction& other) const

	{
		Fraction tempSub;
		Fraction tempSub1;
		if (_denominator != other._denominator)
		{
			tempSub._denominator = _denominator * other._denominator;
			tempSub._numerator = _numerator * other._denominator;
			tempSub1._numerator = _denominator * other._numerator;
			tempSub._numerator = tempSub._numerator - tempSub1._numerator;
		}
		else
		{
			tempSub._numerator = _numerator - other._numerator;
			tempSub._denominator = _denominator;
		}
		return tempSub;
	}

	Fraction operator*(const Fraction& other) const

	{
		Fraction tempMult;

		tempMult._denominator = _denominator * other._denominator;
		tempMult._numerator = _numerator * other._numerator;

		return tempMult;
	}

	Fraction operator/(const Fraction& other) const

	{
		Fraction tempDiv;

		tempDiv._numerator = _numerator * other._denominator;
		tempDiv._denominator = _denominator * other._numerator;

		return tempDiv;
	}

		Fraction operator-() const
	{
		return Fraction(-_numerator, -_denominator);
	}

	Fraction operator==(const Fraction& other) const

	{
		Fraction tempEqu;
		if ((tempEqu._numerator = _numerator == other._numerator) &&
			(tempEqu._denominator = _denominator == other._denominator))
		{
			std::cout << "Fractions are equal" << std::endl;
		}
		else
		{
			std::cout << "Fractions are not equal" << std::endl;
		}
		return tempEqu;
	}

	Fraction operator<(const Fraction& other) const

	{
		Fraction tempEqu;
		if ((_numerator / _denominator) < (other._numerator / other._denominator))
		{
			std::cout << "frac1 is less than frac2" << std::endl;
		}
		else
		{
				std::cout << "frac1 is greater than frac2" << std::endl;
		}
		return tempEqu;
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &frac)
	{
		out << frac._numerator << "/" << frac._denominator;
		return out;
	}
};

int main()

{
	Fraction frac1(2, 3);
	Fraction frac2(5, 8);
	
	std::cout << frac1 << " + " << frac2 << " = " << frac1 + frac2 << std::endl;
	std::cout << frac1 << " - " << frac2 << " = " << frac1 - frac2 << std::endl;
	std::cout << frac1 << " * " << frac2 << " = " << frac1 * frac2 << std::endl;
	std::cout << frac1 << " : " << frac2 << " = " << frac1 / frac2 << std::endl;
	std::cout << "negative value of fraction " << frac1 << " is " << - frac1 << std::endl;
	Fraction resultEqu = frac1 == frac2;
	Fraction resultLess = frac1 < frac2;

	return 0;

}