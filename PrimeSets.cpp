#include <set>
#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin();
		element != container.cend();
		++element)
		cout << *element << ' ';
}

void populate(set<int>& NonPrimes, int max)
{
	int primerange = 0;
	set<int>::iterator primefound;

	primerange = sqrt(max);

	for (int i = 5; i < primerange; ++i)
	{
		primefound = NonPrimes.find(i);
		if (primefound == NonPrimes.end())
			if (i % 2 != 0)
				if (i % 3 != 0)
					for (int j = 5; j <= (max / i); j += 6)
					{
						NonPrimes.insert(j * i);
						NonPrimes.insert((j + 2) * i);
					}
	}
}

bool test_prime(set<int>& NonPrimes, int num)
{
	bool prime = true;
	set<int>::iterator primefound;

	if (num == 1) prime = false;
	if ((num % 2) == 0) prime = false;
	if ((num % 3) == 0) prime = false;
	primefound = NonPrimes.find(num);
	if (primefound != NonPrimes.end()) prime = false;

	return prime;

}

int main()
{
	int max; // user input to represent max range 
	set<int> NonPrimes; // set of numbers that are not primes

	// we'll skip multiples of 2 and 3 to keep the set small

	cout << "Enter the maximum value of the range: ";
	cin >> max;

	populate(NonPrimes, max);
	cout << "Contents of NonPrimes set: " << endl;
	DisplayContents(NonPrimes);
	cout << endl;

	cout << "Primes between 1 and max " << endl;
	cout << "2 3 ";
	for (int i = 0; i < max; ++i)
	{
		if (test_prime(NonPrimes, i)) cout << i << " ";

	}



}