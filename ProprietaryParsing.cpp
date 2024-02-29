#include <iostream>
#include <string>
#include <map>
#include <fstream>



using namespace std;

void parse(const string& input, string& output1, string& output2)
{

	char context = 'Z';
	char buffer = '!';
	output1 = "";
	output2 = "";


	for (string::const_iterator charPos = input.cbegin(); charPos != input.cend(); ++charPos)
	{
		 buffer = *charPos;
		if (buffer == '%')
		{
			context = buffer;
		}
		else
		{
			if (context == 'Z') output1.append(1, buffer);
			if (context == 'A') output2.append(1, buffer);
			if (context == '%') context = buffer;

		};
	}

}

void Load_Database(map<string, string>& CommandCodes)
{
	CommandCodes.insert(make_pair("Picard", "4-1-2-Mark-8-0"));
	CommandCodes.insert(make_pair("La Forge", "Theta-2-9-9-7"));
	CommandCodes.insert(make_pair("Jellico", "Alpha-3-1"));
	CommandCodes.insert(make_pair("Riker", "Alpha-6-0"));
	CommandCodes.insert(make_pair("Troi", "Omega-Omega-3-1"));
	CommandCodes.insert(make_pair("Crusher", "2-2-Beta-Charlie"));
	CommandCodes.insert(make_pair("Worf", "3-7-Gamma-Echo"));
	CommandCodes.insert(make_pair("Bashir", "4-1-2-1"));
	CommandCodes.insert(make_pair("O'Brien", "Epsilon-Alpha-Molly-5-7-9"));
	CommandCodes.insert(make_pair("Sisko", "Alpha-1-Alpha"));
	CommandCodes.insert(make_pair("Kira", "Delta-5-4-7-Alpha"));
	CommandCodes.insert(make_pair("Seska", "937-0176-CE"));
	CommandCodes.insert(make_pair("Janeway", "8-4-1-Alpha-6-5"));
	CommandCodes.insert(make_pair("Tuvok", "1-4-9-4-Lambda"));
	CommandCodes.insert(make_pair("Torres", "Omega-5-9-3"));
	CommandCodes.insert(make_pair("Seven of Nine", "Omega-Phi-9-3"));
	CommandCodes.insert(make_pair("Archer", "Alpha-6-4"));
	CommandCodes.insert(make_pair("Chekov", "9-5-Viktor-Viktor-2"));
	CommandCodes.insert(make_pair("Spock", "Gamma-Delta-2"));
	CommandCodes.insert(make_pair("Pike", "2-4-6-8-10"));
	CommandCodes.insert(make_pair("Barclay", "Alpha-1-7-Gamma"));
	CommandCodes.insert(make_pair("Burnham", "Gamma-6-0-2-Epsilon-Echo"));

}

void write_to_file(const map<string, string>& CommandCodes, const char* filename)
{
	ofstream myFile;
	myFile.open(filename, ios_base::out);

	if (myFile.is_open())
	{
		for (auto element = CommandCodes.cbegin();
			element != CommandCodes.cend();
			++element)
		{
			myFile << element->first << "%A" << element->second << endl;
		}
	}

	myFile.close();
}

void read_file(const char* filename)
{
	string fileinput; 
	string name;
	string code;
	ifstream myFile;
	myFile.open(filename, ios_base::in);

	if (myFile.is_open())
	{
		while (myFile.good())
		{
			getline(myFile, fileinput);
			if (fileinput != "")
			{
				parse(fileinput, name, code);
				cout << name << "'s command code is " << code << endl;
			}
		}
	}

	myFile.close();
}

int main()
{
	const char* filename("commandcodes.txt");
	map<string, string> CommandCodes;
	Load_Database(CommandCodes);
	write_to_file(CommandCodes, filename);
	read_file(filename);

}

