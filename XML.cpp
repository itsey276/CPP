#include <iostream>
#include "tinyxml2.h"
#include <vector>
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace tinyxml2;


XMLError write_xml(char const* savefile)
{
	XMLDocument xmlDoc; // instantiate DOM 

	XMLNode* pRoot = xmlDoc.NewElement("Root"); // create a node called Root
	xmlDoc.InsertFirstChild(pRoot); // attach root node to xmlDoc 

	XMLElement* pElement = xmlDoc.NewElement("IntValue"); // create an element called IntValue
	pElement->SetText(10);                                // give the element an attribute
	pRoot->InsertEndChild(pElement);                      // attach element to root

	pElement = xmlDoc.NewElement("FloatValue");           // create another element called FloatValue
	pElement->SetText(0.5f);                              // give it an attribute that is a float
	pRoot->InsertEndChild(pElement);                      // attach element to root

	pElement = xmlDoc.NewElement("Date");                 // create an element called Date
	pElement->SetAttribute("day", 26);                    // set an attribute pair called "day"
	pElement->SetAttribute("month", "April");             // set an attribute pair called "month"
	pElement->SetAttribute("year", 2014);                 // set an attribute pair called "year"
	pElement->SetAttribute("dateFormat", "26/04/2014");   // set an attribute pair called "dateFormat"

	pRoot->InsertEndChild(pElement);                      // attach the element to root

	pElement = xmlDoc.NewElement("List");                 // create a new element called List

	std::vector<int> vecList = { 0, 1, 1, 2, 3, 5, 8 };

	for (const auto& item : vecList)                      // iterate through vecList and attach each value to List
	{
		XMLElement* pListElement = xmlDoc.NewElement("Item");
		pListElement->SetText(item);

		pElement->InsertEndChild(pListElement);
	}

	pElement->SetAttribute("itemCount", vecList.size());  // set the size attribute for List

	pRoot->InsertEndChild(pElement);                      // attach the List to root


	XMLError eResult = xmlDoc.SaveFile(savefile);   // save Files
	
	return eResult;
}

XMLError read_xml(char const* readfile)
{

	XMLDocument xmlDoc;  // instantiate the DOM object
	XMLError eResult = xmlDoc.LoadFile(readfile);  // load file with error stored in eResult
	XMLCheckResult(eResult);
	std::cout << "Loadfile" << std::endl;

	XMLNode* pRoot = xmlDoc.FirstChild();  // get pointer to the root node

	if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;   // check for empty node and return error

	XMLElement* pElement = pRoot->FirstChildElement("IntValue"); // first child of root named "IntValue" pointer
	if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;  // check for empty element and return error

	int iOutInt;  // storage variable of type int
	eResult = pElement->QueryIntText(&iOutInt); // convert string to int and store in "iOutInt" return error
	XMLCheckResult(eResult);
	std::cout << "Query IntValue" << std::endl;

	pElement = pRoot->FirstChildElement("FloatValue");  // first child of root named "FloatValue"
	if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT; // check for errors

	float fOutFloat;  // storage variable
	eResult = pElement->QueryFloatText(&fOutFloat); // convert string to float 
	XMLCheckResult(eResult); // check for error
	std::cout << "Query FloatValue" << std::endl;

	pElement = pRoot->FirstChildElement("Date");  // first child of root named "Date"
	if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT; // check for errors

	int iOutDay, iOutYear;  // storage variables

	eResult = pElement->QueryIntAttribute("day", &iOutDay);  // get attribute called "day"
	XMLCheckResult(eResult);  // check for error
	std::cout << "Query Date:day " << std::endl;

	eResult = pElement->QueryIntAttribute("year", &iOutYear);  // get attribute called "year"
	XMLCheckResult(eResult);  // check for error
	std::cout << "Query Date:year " << std::endl;

	const char* szAttributeText = nullptr;  // temporary storage variable

	szAttributeText = pElement->Attribute("month");  // get attribute called "month" (c-string)
	if (szAttributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;  // check for error
	std::string strOutMonth = szAttributeText;  // store in string

	szAttributeText = pElement->Attribute("dateFormat");  // get attribute called "dateFormat"
	if (szAttributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE; // check for error
	std::string strOutFormat = szAttributeText; // store in string 

	pElement = pRoot->FirstChildElement("List");  // first child of root called List
	if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT; // check for error

	XMLElement* pListElement = pElement->FirstChildElement("Item"); // first child of List called Item
	std::vector<int> vecList; // storage vector

	while (pListElement != nullptr)  // loop that iterates through the Item elements
	{
		int iOutListValue; // temporary storage variable
		eResult = pListElement->QueryIntText(&iOutListValue); // string to int conversion
		XMLCheckResult(eResult);  // check for error
		std::cout << "Query List values " << std::endl;

		vecList.push_back(iOutListValue);  // load vector

		pListElement = pListElement->NextSiblingElement("Item"); // iterate to next sibling element

	}

	std::cout << "Great Success !! " << std:: endl;
	return XML_SUCCESS;  // if we made it here, then it's a success
	  
}

int main()
{

	write_xml("SaveData3.xml");
	read_xml("SaveData3.xml");



}
