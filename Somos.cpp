#include <iostream>
using namespace std;

long long somos(int n)
{
	if (n < 6) return 1;
	else return (somos(n - 1) * somos(n - 4) + somos(n - 2) * somos(n - 3)) / somos(n - 5);

}

int main()
{
	int terms = 0;
	
	cout << "Enter number of Somos-5 terms to calculate: " << endl;
	cin >> terms;
	cout << "1, 1, 1, 1, 1, ";
	for (int i = 6; i <= terms; ++i)
	{
		cout << somos(i) << ", ";
	}

}