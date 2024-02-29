#include <iostream>
#include <string>
using namespace std;


int copystr(const string& input, string& output, size_t start, size_t strlen)
{

	output = input.substr(start, strlen);
	
	return 0;

}

int GetToken(string& tag, string& Text, string& token, const size_t startPos, size_t& lastPos)
{

	string start_tag = "";
	string end_tag = "";
	size_t start_Pos = 0;
	size_t end_token = 0;
	int copyerror = 0;
	
	start_tag = "<" + tag + ">";
	end_tag = "<" + tag + "/>";

	start_Pos = Text.find(start_tag, startPos);
	end_token = Text.find(end_tag, startPos);
	size_t start_token = start_Pos + start_tag.length();
	size_t token_length = end_token - start_token;
	
	if (start_Pos == string::npos)
		return 3;

	if (end_token == string::npos)
		return 4;

	if (start_token > end_token)
		return 5;

	copyerror = copystr(Text, token, start_token, token_length);
	

	if (copyerror != 0)
		return copyerror;  // returns 1 if input is null, 2 if copy range out of bounds
	else {
		lastPos = end_token + end_tag.length();
		return 0;  // return 3 if no tag found; 4 if end tag not found; 5 if tag order was reversed
		}
}


int main()
{
	string text = "12345<message>All these worlds are yours except Europa.<message/>";
	string tag = "message";
	string token = "";
	size_t lastPos = 0;
	size_t startPos = 0;

	GetToken(tag, text, token, startPos, lastPos);
	cout << "Token is: " << token << endl;

	return 0;
}