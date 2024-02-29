#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() 

{
	const char* sentence = "What kind of thing is this?";
	string statement = "It is what dreams are made of.";
	string emphatic(sentence, 10);

	cout << sentence << endl;
	cout << statement << endl;
	transform(emphatic.begin(), emphatic.end(), emphatic.begin(), ::toupper);
	cout << emphatic << endl;
	cout << *(statement.begin()+4);
}

