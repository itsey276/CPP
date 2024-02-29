#include <iostream>
#include <string>
#include <stack>
#include <fstream>

using namespace std;


int parse(const string& input)
{


	string contentbuffer = "";
	string value = "";
	char buffer = '\0';
	bool inside = false;
	bool terminal = false;
	bool attribute = false;
	stack <string> tagstack;
	string tag = "";
	string tagtop = "mydoc/";
	tagstack.push(tagtop);
	string path = tagtop;
	int path_end = 0;
	int path_pos = 0;
	int tag_length = 0;

	
	std::cout << path << '\t' << '\t' << '\t';
	for (string::const_iterator charPos = input.cbegin(); charPos != input.cend(); ++charPos)
	{
		buffer = *charPos;

		if (buffer == '>')
		{
			inside = false;;
			tagtop = tagstack.top();
			if (tag == tagtop)
			{
				tag_length = tag.length() + 1;
				path_end = path.length() - 1;
				path_pos = path_end - tag_length;
				tagstack.pop();
				path.erase(path_pos, tag_length);
			}
			else
			{
				tagstack.push(tag);
				path.append(tag);
				path.append("/");
			}
			
			tag = "";

			tagtop = tagstack.top();
			std::cout << contentbuffer;
			contentbuffer = "";

			if (value != "")
				cout << endl << path << '\t' << value << endl;
			value = "";


			std::cout << '\n' << path;
			std::cout << '\t' << '\t' << '\t';


		}
		else if (buffer == '<')
		{
			inside = true;
			terminal = false;
			attribute = false;
		}
		else if (buffer == ' ')
		{
			attribute = true;
		}
		else if (buffer == '/')
		{
			terminal = true;
		}

		else if (inside == false)
			contentbuffer.append(1, buffer);

		else if (attribute == true)
			value.append(1, buffer);
		else tag.append(1, buffer);

		
	}

	std::cout << contentbuffer;

	if (tagstack.size() > 1)
		return 1;
	else return 0;
}

int read_file(const char* filename, string& text)
{
	string fileline;
	text = "";

	ifstream myFile;
	myFile.open(filename, ios_base::in);

	if (myFile.is_open())
	{
		while (myFile.good())
		{
			getline(myFile, fileline);
			text.append(fileline);
			text.append(1, '\n');
			fileline = "";

		}
		return 0;
	}
	else return 1;
}


int main()
{

	const char* filename("XMLFile.xml");
	string xmltext = "";

	read_file(filename, xmltext);

	int error_check = 0;
	error_check = parse(xmltext);
	if (error_check > 0)
	    std::cout << "Error! Malformed XML detected." << endl;
    std::cout << endl;


}