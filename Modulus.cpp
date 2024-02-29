#include <iostream>
using namespace std;

int main()
{
	int input = 0;
	
	cout << "Enter a number between 11 and 100" << endl;
	cin >> input;

	if (input < 11 or input > 100)
		cout << "Error: number not in range" << endl;
	else
	{
		int count = 0;
		count = input % 11;

		for (int i = 0; i <= count; ++i)
			cout << input - i << ", ";
		cout << endl;
	}

	return 0;
}
