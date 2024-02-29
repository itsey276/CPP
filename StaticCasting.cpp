#include <iostream>
using namespace std;

int main()
{
	float Pi = 22.0 / 7;
	int pi = static_cast <int>(Pi);

	cout << "Appromximately Pi: " << Pi << endl;
	cout << "Pi truncated to integer: " << pi << endl;

	return 0;
}

