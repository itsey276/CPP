#include <iostream>
using namespace std;

int main()  // this is how we used to program loops in Basic
{

int counter = 0;
int max = 10;

cout << "Counting down from 10: " << endl;

Start:    
cout << max - counter << endl;
counter += 1;

if (counter < max) goto Start;

	return 0;
}