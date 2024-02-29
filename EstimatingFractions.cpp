#include <iostream>
using namespace std;

long int gcd(long int a, long int b, int tolerance)
{
	long int swap = 0;
	while (b > tolerance)
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
	int tolerance = 0;
	int iterate = 1;

	cout << "Enter the numerator: ";
	cin >> num;
	cout << endl << "Enter the denominator: ";
	cin >> denom;
	cout << endl;
	cout << "Enter the tolerance: " << endl;
	cin >> tolerance;


	while (iterate == 1)
	{
		GCD = gcd(num, denom, tolerance);
		num /= GCD;
		denom /= GCD;
		cout << "Estimated fraction: " << num << "/" << denom << endl;
		cout << "Continue to iterate? (1-Yes, 2-No): " << endl;
		cin >> iterate;
	}

	return 0;
}