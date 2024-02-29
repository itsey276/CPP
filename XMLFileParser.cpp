#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <map>

using namespace std;

class XMLDoc
{
private:
	string outputtext;
	string inputtext;
	string file;
	string contentbuffer;
	string oldpath;
	map<string, string> xmlmap;

public:
	XMLDoc(const string inputfile)
	{
		file = inputfile;
		inputtext = "";
		outputtext = "";
		xmlmap = {};

	}

	int read_file()
	{
		string fileline;
		inputtext = "";

		ifstream myFile;
		myFile.open(file, ios_base::in);

		if (myFile.is_open())
		{
			while (myFile.good())
			{
				getline(myFile, fileline);
				inputtext.append(fileline);
				fileline = "";

			}
			return 0;
		}
		else return 1;
	}

	bool empty()
	{
		for (auto element = contentbuffer.begin();
			element != contentbuffer.end();
			++element)
			if (*element == ' ' || *element == '\n' || *element == '\t') {}
			else return false;
		return true;
	}

	void add_to_map()
	{
		bool duplicate = false;
		auto pairfound = xmlmap.find(oldpath);
		
		if (pairfound == xmlmap.end())
		{
			xmlmap.insert(make_pair(oldpath, contentbuffer));
		}
		else
		{
			pairfound->second = pairfound->second.append(contentbuffer);
		}

	}

	void print_map()
	{
		cout << "Contents of map: " << endl;
		for (auto element = xmlmap.begin();
			element != xmlmap.end();
			++element)
		{
			cout << element->first << ":  " << element->second << endl;
		}

	}


	int parse()
	{
		stack <string> tagstack;
		string value = "";
		string tag = "";
		string tagtop = file;
		string path = tagtop + '/';
		oldpath = "";
		contentbuffer = "";
		char buffer = '\0';
		bool inside = false;
		bool terminal = false;
		bool attribute = false;
		int path_end = 0;
		int path_pos = 0;
		int tag_length = 0;

		tagstack.push(tagtop);

		for (string::const_iterator charPos = inputtext.cbegin(); charPos != inputtext.cend(); ++charPos)
		{
			buffer = *charPos;

			if (buffer == '>')
			{
				inside = false;;
				tagtop = tagstack.top();
				oldpath = path;
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

				if (empty() == false)
				{
					outputtext += oldpath;   // output of xml content
					outputtext += '\t';
					outputtext += '\t';
					outputtext += '\t';
					outputtext += contentbuffer;
					outputtext += '\n';
					add_to_map();

				}

				tag = "";
				tagtop = tagstack.top();
				contentbuffer = "";

				if (value != "")
				{
					
					oldpath = path + "attrib";
					contentbuffer = value;
					
					if (empty() == false)
					{
						outputtext += oldpath + '\t'+ value + '\n';  // output of tag attributes
						add_to_map();
					}
					contentbuffer = "";
				}
				value = "";
			}
				else if (buffer == '<')
				{
					inside = true;
					terminal = false;
					attribute = false;
				}
				else if ((inside) && (buffer == ' '))
				{
					attribute = true;
					value += ' ';
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
		outputtext += '\n' + path + contentbuffer;  // final output line
		oldpath = path;
		add_to_map();

		if (tagstack.size() > 1)
			return 1;
		else return 0;
	}

string output()
	{
		return outputtext;
	}

};
int main()
{
	string filename = "";
	int error = 0;

	cout << "Enter file name to parse: " << endl;
	cin >> filename;

	XMLDoc myDoc(filename);
	error = myDoc.read_file();
	if (error != 0)
		cout << "Error reading file!" << endl;

	error = myDoc.parse();
	if (error != 0)
		cout << "Malformed XML detected!" << endl;
	else cout << myDoc.output();

	myDoc.print_map();

}