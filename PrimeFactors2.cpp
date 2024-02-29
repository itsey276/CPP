#include <iostream>
#include <vector>
using namespace std;

bool Prime(int Num, vector<int> &PrimeArray)
{
	int init = Num;
	bool found = false;
	float Q = 0;

	while (Num > 1)
	{
		found = false;
		Q = sqrt(Num);

		if (Num % 2 == 0)
		{
			PrimeArray.push_back(2);
			Num = Num / 2;
			found = true;
		}

		if (Num % 3 == 0)
		{
			PrimeArray.push_back(3);
			Num = Num / 3;
			found = true;

		}
				
		if (not found)
		for (int i = 5; i <= Q; i += 6)
		{
			if ((Num % i) == 0)
			{
				PrimeArray.push_back(i);
				Num = Num / i;
				found = true;
			}

			if ((Num % (i + 2)) == 0)
			{
				PrimeArray.push_back(i + 2);
				Num = Num / (i + 2);
				found = true;
			}

		}

		if (not found)
		{
			if (Num == init)
				return 1;
			else
				PrimeArray.push_back(Num);
			Num = 1; // ends loop

		}
	}

	return 0;
}

int main()
{
	int num = 0;
	bool primetest = 0;
	vector<int> PrimeArray(1); // dynamic array of int
	PrimeArray[0] = 1;

	cout << "Enter a number greater than 1: ";
	cin >> num;
	if (num > 1)
	{
		primetest = Prime(num, PrimeArray);
		if (primetest)
			cout << "Prime";
	}
}