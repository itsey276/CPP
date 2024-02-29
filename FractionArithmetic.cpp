#include <iostream>
using namespace std;

template <typename Type>
class fraction
{
public:
	Type numerator;
	Type denominator;

	fraction()
	{
		numerator = 1;
		denominator = 1;
	}

	Type gcd(Type a, Type b)
	{
		Type swap = 0;

		while (b != 0)
		{
			swap = b;   // implement's Euclid's algorithm for finding gcd
			b = a % b;
			a = swap;
		}

		return a;
	}

	fraction& operator ! ()
	{
		Type GCD;
		GCD = gcd(numerator, denominator);
		numerator = numerator / GCD;
		denominator = denominator / GCD;
		return *this;

	}

	fraction operator / (fraction divisor)
	{
		numerator = numerator * divisor.denominator;
		denominator = denominator * divisor.numerator;
		return *this;
	}

	fraction operator * (fraction mult)
	{
		numerator = numerator * mult.numerator;
		denominator = denominator * mult.denominator;
		return *this;
	}

	fraction operator + (fraction factor)
	{
		Type GCD;
		Type common;
		Type numsum;

		GCD = gcd(denominator, factor.denominator);
		numsum = numerator * factor.denominator / GCD + factor.numerator * denominator / GCD;
		common = denominator * factor.denominator / GCD;
		numerator = numsum;
		denominator = common;
		return *this;
	}

	fraction operator - (fraction factor)
	{
		Type GCD;
		Type common;
		Type numsum;

		GCD = gcd(denominator, factor.denominator);
		numsum = numerator * factor.denominator / GCD - factor.numerator * denominator / GCD;
		common = denominator * factor.denominator / GCD;
		numerator = numsum;
		denominator = common;
		return *this;
	}

};

int main()
{
	fraction <long int>a;
	fraction <long int>b;
	int input;

	cout << "Enter a, b as fractions: " << endl;
	cout << "a numerator: ";
	cin >> a.numerator;
	cout << "a denominator: ";
	cin >> a.denominator;
	cout << "b numerator: ";
	cin >> b.numerator;
	cout << "b denominator: ";
	cin >> b.denominator;

	cout << "Choose operation (1 - add, 2 - subtract, 3 - multiply, 4 divide): ";
	cin >> input;
	
	if (input == 1) a + b;
	if (input == 2) a - b;
	if (input == 3) a * b;
	if (input == 4) a / b;
	!a;
	
	cout << "Result: " << a.numerator << "/" << a.denominator << endl;


}


