#include<map>
#include<iostream>

using namespace std;


struct  ReverseSort
{
	bool operator() (const string& key1, const string& key2) const
	{
		return (key1 > key2);
	}

};

template<typename T>
void DisplayContents(const T& codes)
{
	for (auto element = codes.cbegin();
		element != codes.cend();
		++element)
		cout << element->first << " -> " << element->second << endl;
	cout << endl;
}

void Load_Database(map<string, string, ReverseSort>& CommandCodes)
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

void Hack(map<string, string>& CommandCodes)
{
	string key = "";
	string command = "";
	cout << "Enter search parameters: " << endl;
	cin >> key;

	auto CodeFound = CommandCodes.find(key);

	if (CodeFound != CommandCodes.end())
	{
		cout << "Command Code located for " << CodeFound->first << endl;
		cout << "Code: " << CodeFound->second << endl;
	}
	else cout << "No command codes found for this personnel." << endl;

	cout << "Command: ";
	cin >> command;
	cout << endl;
	cout << "Code Entered." << endl;
	cout << "Do you wish to: " << endl;
	cout << "1) Deactivate shields." << endl;
	cout << "2) Terminate life support." << endl;
	cout << "3) Vent atmosphere." << endl;
	cout << "4) Disable all command terminals." << endl;
	cout << "5) Activate Auto Destruct (1 minute countdown)." << endl;
	cin >> command;
	cin >> command;
	cout << endl;
	cout << "Command Acknowledged." << endl;


}


int main()
{
	map<string, string, ReverseSort> CommandCodes;
	Load_Database(CommandCodes);
	DisplayContents(CommandCodes);

	return 0;
}