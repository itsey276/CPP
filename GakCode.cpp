#include <iostream>
#include <string>
#include <tuple>

using namespace std;

class XMLParser
{
private:
    string Input;
    string Output;
    int Pos;

    std::tuple<string, bool> GetContentUntil(char SearchCh)
    {
        int StartPos = Pos;
        int EndPos = Input.find(SearchCh, StartPos);
        if (EndPos == string::npos) {
            Pos = Input.length();
            return { Input.substr(StartPos), false };
        }
        else {
            Pos = EndPos + 1;
            return { Input.substr(StartPos, EndPos - StartPos), true };
        }
    }

    bool ParseTags(const string EndTag = "", const string DepthStr = "")
    {
        string Content;
        bool Found;
        while (Pos < Input.length()) {
            tie(Content, Found) = GetContentUntil('<');
            Output += DepthStr + Content + '\n';
            if (!Found) continue;
            tie(Content, Found) = GetContentUntil('>');
            if (!Found) continue;
            if (Content.compare(EndTag) == 0) return true;
            if (Content[0] == '/') return false;
            if (!ParseTags('/' + Content, '\t' + DepthStr)) return false;
        }
        return (DepthStr.length() == 0); // make sure we don't have any unterminated tags
    }

public:
    string Parse(const string& XML)
    {
        Input = XML;
        Output = "The XML parses as:\n";
        Pos = 0;
        if (ParseTags()) {
            return Output;
        }
        else {
            return "malformed XML!";
        }
    }
};

int main()
{
    string Test = "000<tagA>ABC<tagB>textB</tagB>123<tagC>textC</tag>do-re-me</tagA>fghfghfgh";
    XMLParser XMLParse;
    cout << XMLParse.Parse(Test);
}
