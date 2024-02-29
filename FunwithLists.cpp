#include <iostream>
#include <list>

using namespace std;

void getFib(list<int>* input, int n)
{
	int a = 0;
	int b = 1;
	int swap = 0;

	input->push_back(a);                 // loads initial values
	input->push_back(b);

	for (int i = 0; i < n; ++i)          // generates Fibonacci numbers
		{ 
		swap = b;
		b = a + b;
		a = swap;
		input->push_back(b);             // loads numbers onto list
		}

}

void DisplayList(list<int>* output)
{
	for (auto element = output->cbegin(); // iterator traversal loop
		element != output->cend();
		++element)
		cout << *element << ' ';     // prints out elements
}

int main()
{
	int terms = 0;
	cout << "Enter number of Fibonacci terms to get: ";
	cin >> terms;
	list<int> Fibonacci = {};        // instantiate empty list
	getFib(&Fibonacci, terms);       // populate list
	DisplayList(&Fibonacci);         // display list
	cout << endl;
	cout << "Reversing order of list elements: " << endl;
	Fibonacci.reverse();
	DisplayList(&Fibonacci);
	cout << endl;
	
}