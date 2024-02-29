#include<map>
#include<iostream>
#include <iomanip>
#include<string>
#include "tinyxml2.h"
#include <fstream>

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace tinyxml2;
using namespace std;

XMLError write_xml(const char* savefile, const map<string, string>& codes)
{
	XMLDocument xmlDoc;                          // instantiate DOM 

	XMLNode* pRoot = xmlDoc.NewElement("Root");  // create a node called Root
	xmlDoc.InsertFirstChild(pRoot);              // attach root node to xmlDoc 

	XMLElement* pElement = xmlDoc.NewElement("Personnel"); // create an element called Personnel

	string key = ""; // temporary variables
	string personnel = ""; // temporary variables

	for (auto element = codes.cbegin();          //  loop with iterator
		element != codes.cend();
		++element)
	{
		personnel = element->first;
		key = element->second;
		cout << personnel << " : " << key << endl;
		XMLElement* pListElement = xmlDoc.NewElement(personnel.c_str()); 
		pListElement->SetAttribute("Code:", key.c_str());  
		pElement->InsertEndChild(pListElement);  

	}

	pElement->SetAttribute("entries: ", codes.size());  

	pRoot->InsertEndChild(pElement);                     

	XMLError eResult = xmlDoc.SaveFile(savefile);   

	return eResult;
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

void write_text(const char* myfile, const map<string, string>& CommandCodes)
{
	ofstream MyFile;
	MyFile.open(myfile, ios_base::out | ios_base::trunc);

	if (MyFile.is_open())
	{
		MyFile << left << setw(15) << "NAME" << left << setw(20) << "CODE" << endl;

		for (std::map<string, string>::const_iterator element = CommandCodes.cbegin(); 
			element != CommandCodes.cend();
			++element)
			MyFile << left << setw(15) << element->first << left << setw(20) << element->second << endl;
	}

	MyFile.close();

}

void read_text(const char* myfile)
{
	ifstream myFile;
	myFile.open(myfile, ios_base::in);

	if (myFile.is_open())
	{
		cout << "File open successful. It contains: " << endl;
		string fileContents;

		while (myFile.good())
		{
			getline(myFile, fileContents);
			cout << fileContents << endl;
		}

		cout << "Finished reading this file, will close now." << endl;
		myFile.close();

	}

	else cout << "open() failed: check filename" << endl;
}

int main()
{
	// XMLError alert;
	// map<string, string> CommandCodes;
	// Load_Database(CommandCodes);
	// write_text("Starfleetcodes2.txt", CommandCodes);
	// XMLCheckResult(alert);
	read_text("Starfleetcodes2.txt");

	return 0;
}