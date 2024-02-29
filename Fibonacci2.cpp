#include <iostream>
using namespace std;

int Fibonacci(int findex)
{
	if (findex < 2) // stop condition
		return findex;
	else // recursively find the values
		return Fibonacci(findex - 1) + Fibonacci(findex - 2);
}

int main()
{
	cout << "Enter the index of the Fibonacci term you wish to calculate: ";
	int index = 0;
	cin >> index;

	cout << "The corresponding Fibonacci term is: " << Fibonacci(index) << endl;
	return 0;
}
