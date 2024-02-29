#include <iostream>
#include <map>
#include <string>

using namespace std;

class StreamParser {
public:
	string tag;
	bool success;
	bool read;
	string text;
	string attribute;
	string type;

	StreamParser() {
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

	void reset() {
		tag = "";
		success = false;
		read = false;
		type = "begin";
		text = "";
	}

};

multimap<string, string> parse(string text) {
	StreamParser parser;
	string path = "/document";
	multimap<string, string> docMap;
	bool found;

	for (auto buffer : text) {

		found = parser.parse(buffer);
		if (found) {
			if (parser.type == "format")
				docMap.insert(make_pair(parser.tag, 
					parser.attribute.erase(parser.attribute.length() - 1, 1)));
			if (parser.type == "begin") {
				if (parser.text != "") docMap.insert(make_pair(path, parser.text));
				path = path + '/' + parser.tag;
				if (parser.attribute != "")
					docMap.insert(make_pair(path + "/attribute", parser.attribute));
			}

			if ((parser.type == "end") && 
				(parser.tag != path.substr(path.length() - parser.tag.length(), path.length() - 1)))
					cout << "Error: tag mismatch" << endl;

			if ((parser.type == "end") && 
				(parser.tag == path.substr(path.length() - parser.tag.length(), path.length() - 1)))
				{
					docMap.insert(make_pair(path, parser.text));
					path = path.substr(0, path.length() - parser.tag.length() - 1);
				}

			parser.reset();
		}
	}
	return docMap;
}

void DisplayContents(multimap<string, string>& docMap) {

	for (auto element = docMap.cbegin();
		element != docMap.cend();
		++element)
		cout << element->first << " -> " << element->second << endl;
	cout << endl;

}

int main()
{
	multimap<string, string> docMap;
	string test = "<?xml version='1.0' encoding='UTF-8'?><test start = true>this is<level> another level </level> a test message </test>";
	docMap = parse(test);
	DisplayContents(docMap);

	return 0;
}
