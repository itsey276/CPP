#include <iostream>
using namespace std;

class Prime
{
public:
	
	int input;
	int nextprime;

	bool isPrime(int num)
	{

		if (num <= 1)  return false;
		if (num <= 3)  return true;

		if (num % 2 == 0 || num % 3 == 0) return false;

		for (int i = 5; i * i <= num; i = i + 6)
			if (num % i == 0 || num % (i + 2) == 0)
				return false;

		return true;
	};


	Prime()
	{
		input = 1;
		nextprime = 2;
		
	}

	Prime& operator ++ ()
	{

		// Base case

		int prime = input;
		bool found = false;


		while (!found) 
		{
			prime++;

			if (isPrime(prime))
				found = true;
		}
		
		nextprime = prime;

		return *this;
	}
		
};

	int main()
	{ 
		Prime MyNumber;
		int MaxNumber;

		cout << "Input a starting number: ";
		cin >> MyNumber.input;
		cout << "Input the maximum number: ";
		cin >> MaxNumber;

		do
		{
			++MyNumber;
			MyNumber.input = MyNumber.nextprime;
			if (MyNumber.nextprime < MaxNumber) cout << ", " << MyNumber.nextprime << endl;
		} while (MyNumber.nextprime < MaxNumber);

		return 0;
	}
