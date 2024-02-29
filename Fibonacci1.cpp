#include <iostream>
#include <vector>
using namespace std;

vector<unsigned long long int> Fibonacci (2); // these are very large numbers
unsigned long long int NextNum = 0;           // to match size of Fibonacci
int MaxTerm = 0;

int main()
{
	Fibonacci[0] = 0;  // initialize initial values
	Fibonacci[1] = 1;  // For the Fibonacci sequence

	cout << "Enter number of Fibonacci terms to calculate: ";
	cin >> MaxTerm;    // user entered value to iterate

	for (int counter = 2; counter < MaxTerm; ++counter)
	{
		NextNum = Fibonacci[counter - 1] + Fibonacci[counter - 2];   // calculate the next term
		Fibonacci.push_back(NextNum);                                // add result to end of vector
	}

	cout << "The first " << MaxTerm << " Fibonacci numbers are: " << endl;

	for (int element = 0; element < (MaxTerm-1); ++element)
	{
		cout << Fibonacci[element] << ", ";    // print values in the vector
	}
	cout << Fibonacci[MaxTerm-1] << "." << endl; // end sentence


	return 0;
}