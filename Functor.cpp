#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename elementType>
struct SquareRoot
{
	int count;

	SquareRoot() : count(0) {};

	float operator()(elementType& S)
	{

		float guess = 0.5 * S;
		float tolerance = 1e-3;
		count = 0;

		while (abs(S - (guess * guess)) > tolerance)
		{
			guess = 0.5 * (guess + S / guess);
			count += 1;
		}
		return guess;
	}
};




int main()
{
	vector<int> testnums{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	for_each(testnums.begin(),
		testnums.end(),
		[](const int& element) {cout << "Square root of " << element << " = " << sqrt(element) << ' ' << endl; });

	cout << endl;
	

}