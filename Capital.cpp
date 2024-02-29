#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
	string input = "";
	string keyword = "";
	size_t CharPos = 0;
	int keylength = 0;

	cout << "Input a sentence: ";
	getline (cin, input);
	cout << "Input a search term: ";
	cin >> keyword;
	keylength = keyword.length();

	CharPos = input.find(keyword, 0);

	if (CharPos != string::npos)
		transform(input.begin() + CharPos, input.begin() + CharPos + keylength, input.begin() + CharPos, ::toupper);
	
	cout << "Capitalized: " << input << endl;



}