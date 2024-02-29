#include <iostream>
#include <string>
using namespace std;

float significant(float num, int sigs) {
	int non_sig = 0;
	int start = 0;
	int decimal = 0;
	int count = 0;
	int zeros = 0;
	string numstring = to_string(num);
	char charbuffer = NULL;
	string whitespace = "0.";

	for (int i = 0; i < numstring.length(); ++i) {
		charbuffer = numstring[i];
		if (whitespace.find(charbuffer) != string::npos && start == 0)
			++non_sig;
		else start = non_sig;
		if (charbuffer == '.')
			decimal = 1;
		else ++count;
		if (count > sigs && decimal == 0)
			++zeros;
	}

	if (sigs == 0)
		return 0;
	if (zeros > 0)
		return stof(numstring.substr(0, sigs));
	if (num > 1)
		return stof(numstring.substr(0, sigs + decimal));
	else
		return stof(numstring.substr(0, start + sigs));
}


int main()
{
	float test = 0.12345;
	float output = 0;

	for (int i = 0; i < 10; ++i) {
		output = significant(test, i);
		cout << i << ": " << output << endl;
	}

	return 0;

}