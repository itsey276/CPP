#include <iostream>
using namespace std;

int Primetest(int N)
{
	int prime = 0;

	if (N <= 1) return 1;
	if (N % 2 == 0) return 2;
	if (N % 3 == 0) return 3;

	float max = 0;
	max = sqrt(N);

	for (int i = 5; i < max; i += 6)
	{
		if (N % i == 0) prime = i;
		else if (N % (i + 2) == 0) prime = i + 2;
	}

	return prime;
}

int main()
{
	int Remainder = 0;
	int Factor = 0;

	cout << "Input a number " << endl;
	cin >> Remainder;
	cout << "The prime factors of this number are: ";

	while(Remainder > 1)
	{
		Factor = Primetest(Remainder);
		if(Factor == 0)
		{
			cout << Remainder << ".";
			Remainder = 1;
		}
		else
		{
			cout << Factor << " ";
			Remainder = Remainder / Factor;
		}
	}

	cout << endl;

	return 0;

}