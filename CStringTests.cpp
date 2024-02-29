#include <iostream>
using namespace std;


int main()
{
	char CStyleString[] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '.', '\0'};
	cout << CStyleString << endl;
	cout << "size by sizeof(): " << sizeof(CStyleString) << endl;
	cout << "size by strlen(): " << strlen(CStyleString) << endl;


}