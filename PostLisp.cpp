#include <iostream>
using namespace std;


template <typename Type>
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

template <typename Type>
Type gcd2(Type a, Type b)
{
	if (!b) return a;
	return gcd2(b, a % b);

}

int main()
{
	cout << "The greatest common divisor of 77 and 21 (old style) " << gcd<int>(77, 7) << endl;

	cout << "The greatest common divisor of 88 and 56 (new style) " << gcd2<int>(88, 8) << endl;

	return 0;

}