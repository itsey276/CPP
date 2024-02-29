#include <iostream>
using namespace std;

long int gcd(long int a, long int b)
{
	long int swap = 0;
	while (b != 0)
	{
		swap = b;   // implement's Euclid's algorithm for finding gcd
		b = a % b;
		a = swap;

	}

	return a;
}

int main()
{
	long int num = 0;
	long int denom = 0;
	long int GCD = 0;
	long int sign = 1;

	cout << "Enter the numerator: ";
	cin >> num;
	cout << endl << "Enter the denominator: ";
	cin >> denom;
	cout << endl;

	if (num * denom < 0)
	sign = -1;
	if (num < 0) num = -num;
	if (denom < 0) denom = -denom;

	GCD = gcd(num, denom);
	
	if (GCD == 1)
		cout << "The fraction is already in reduced form!" << endl;
	else if (denom == GCD)
		cout << "The fraction reduces to: " << sign * (num / GCD) << endl;
	else cout << "The reduced fraction is: " << sign * (num / GCD) << " / " << (denom / GCD) << endl;

	return 0;
}