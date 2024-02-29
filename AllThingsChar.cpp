#include <iostream>
using namespace std;


int main()
{
	const char* cstring = "This is a static c-string.";
	const char* cstring2("Another static c-string. Initialized differently.");
	char cstring3[50]("A C-String limited to 50 characters.");
	char cstring4[20];

	cout << cstring << endl;
	cout << cstring2 << endl;
	cout << cstring3 << endl;
	cout << "Don't enter more than 19 characters." << endl;
	cin >> cstring4;
	if (strlen(cstring4) > 19)
		cout << "C-String limit exceeded!";
	else cout << "Valid string: " << cstring4 << endl;




}