#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>

using namespace std;

void GetKeys(list<string>* mykeys)
{

	// One-time encryption keys. Do not re-use! //
	string key1 = "nsywwhgubnwgTsgwsIHSIN%IOV&WWNVssxshxisothw6nhi8wnwi9sfnwourghJSGwghowiH";
	string key2 = "jsuJshsjBhwsolKhwhxuUqs$qJshgiqUHUssuw@sjiwslvhysxkwn78nJGHWwhsyiwnSJNwh";
	string key3 = "hhwJGHsutnshTbuywV272gGsutNS8wn@sutnhy2hs78hsghJSHT82hg2j828@@72sjwusj2h";

	mykeys->push_back(key1);
	mykeys->push_back(key2);
	mykeys->push_back(key3);
}

void print_ASCII(const string* output)  // prints out the ASCII value of the char in a string
{
	char c;
	string::const_iterator strchar;
	strchar = output->cbegin();

	for (int i = 0; i < output->length(); i++)
	{ 
		c = *strchar;
		cout << (int)c << " ";
		++strchar;
	}
}

std::string XOR(const string* message, const string* key)
{
	// this algorithm is used both to encrypt and decrypt using bit-wise xor 

	int len = message->length();
	string::const_iterator message_char = message->cbegin();
	string::const_iterator key_char = key->cbegin();
	string cypher = "";
	char crypt;

	for (int i = 0; i < len; ++i)
	{ 
		crypt = *message_char ^ *key_char;
		cypher += crypt;
		++message_char;
		++key_char;
	}

	return cypher;

}

void key_generate(string& keystring, unsigned int seed, int n)
{
	string output = "";
	char ranchar = 'c';
	int rannum = 0;


	srand(seed);
	for (int i = 0; i < n; ++i)
	{
		rannum = rand() % 94 + 32;
		ranchar = (char)rannum;
		output += ranchar;
	}

	keystring = output;
}

string convert_to_string(list<int>& message)
{
	string output = "";
	char nextchar = 'c';
	int listlength = 0;
	list<int>::const_iterator element;

	element = message.cbegin();
	listlength = message.size();

	for (int i = 0; i < listlength; i++)
	{
		nextchar = (char)*element;
		output += nextchar;
		++element;

	}

	return output;
	
}


int main()
{
	list<std::string> mykeys;                // instantiate a list of strings containing keys
	list<string>::const_iterator element;    // an iterator that is used to select the key sequence
	string key;                              // selected encryption / decryption key
	string message;                          // plain-text message for encryption
	string cypher;                           // encrypted string
	string decrypt;                          // decrypted plain-text message for verification
	int choice = 0;                          // user selects a key sequence to use
	unsigned int seed = 0;                   // random seed for key_generate
	int n = 0;                               // input for number of iterations - required by key generate
	list<int> intercept = { 72, 69, 76, 76, 79, 32, 87, 79, 82, 76, 68 };  // test sequence for convert to string - "HELLO WORLD"


	cout << "Enter message to encrypt: " << endl;
	getline(cin, message);
	cout << "Choose key sequence to use: (1 - 3): ";
	cin >> choice;
	
	GetKeys(&mykeys);
	element = mykeys.cbegin();
	for (int i = 1; i < choice; ++i) ++element;
	key = *element;                          // selects key matching user choice


	// the message must not exceed the length of the key to ensure cryptographic security
	if (message.length() > key.length())
		cout << "Message is too long. Please limit message to " << key.length() << " characters." << endl;
	else
	{ 
		cypher = XOR(&message, &key);
		cout << endl << "Encrypted Message by ASCII values: " << endl; 
		print_ASCII(&cypher);  // this cypher text can be transmitted in the clear

		decrypt = XOR(&cypher, &key);
		cout << std::endl << endl << "Decrypted message: " << endl;
		cout << decrypt << endl; // verification that cypher text can be decrypted correctly
	
	}
		
}