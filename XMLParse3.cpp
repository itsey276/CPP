#include <iostream>
#include <map>
#include <string>

using namespace std;

class StreamParser {
private:
	string tag;
	bool success;
	bool read;
	string text;
	string attribute;
	string type;
	string source;

	void reset() {
		tag = "";
		success = false;
		read = false;
		type = "begin";
		text = "";
	}

	bool parse(char buffer) {

		if (buffer == '<') read = true;
		if ((read) && (buffer == '>'))
			success = true;

		if (success) {
			if (tag[1] == '/') {
				type = "end";
				tag.erase(0, 1);
			}

			if (tag[1] == '?') {
				type = "format";
				tag.erase(0, 1);
			}

			string delimiter = " ";
			string coretag = tag.substr(0, tag.find(delimiter));

			attribute = tag.substr(coretag.length(), tag.length() - 1);
			tag = coretag.erase(0, 1);

			return true;
		}
		else if (read) tag += buffer;
		else text += buffer;

		return false;

	}

	void parser() {

		string path = "/document";
		bool found;

		for (auto buffer : source) {

			found = parse(buffer);
			if (found) {
				if (type == "format")
					docMap.insert(make_pair(tag,
						attribute.erase(attribute.length() - 1, 1)));
				if (type == "begin") {
					if (text != "") docMap.insert(make_pair(path, text));
					path = path + '/' + tag;
					if (attribute != "")
						docMap.insert(make_pair(path + "/attribute", attribute));
				}

				if ((type == "end") &&
					(tag != path.substr(path.length() - tag.length(), path.length() - 1)))
					cout << "Error: tag mismatch" << endl;

				if ((type == "end") &&
					(tag == path.substr(path.length() - tag.length(), path.length() - 1)))
				{
					docMap.insert(make_pair(path, text));
					path = path.substr(0, path.length() - tag.length() - 1);
				}

				reset();
			}
		}
	}


public:

	multimap<string, string> docMap;

	StreamParser(string input) {
		tag = "";
		success = false;
		read = false;
		type = "begin";
		text = "";
		source = input;
		parser();

	}

};


void DisplayContents(multimap<string, string>& docMap) {

	for (auto element = docMap.cbegin();
		element != docMap.cend();
		++element)
		cout << element->first << " -> " << element->second << endl;
	cout << endl;

}

int main()
{

	string test = "<?xml version='1.0' encoding='UTF-8'?><test start = true>this is a test<level> another level </level>this is only a test</test>";
	StreamParser Parse(test);
	DisplayContents(Parse.docMap);

	return 0;
}
