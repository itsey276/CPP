#include <iostream>
#include <string>

using namespace std;


void parse(const string& input, const string& tagA, const string& tagB, const string& tagC, string& A, string& B, string& C)
{

    string context = "PartA";
    string nextcontext = "";
    char control = '\0';
    char buffer = '!';
    A = "";
    B = "";
    C = "";

    for (string::const_iterator charPos = input.cbegin(); charPos != input.cend(); ++charPos)
    {
        buffer = *charPos;

        if ((buffer == '<') or (buffer == '>'))
        {
            control = buffer;
            if (control == '>')
            {
                context = nextcontext;
                nextcontext = "";
            }

        }
        else
        {

            if (control == '<')
                nextcontext += buffer;
            else
            {
                if (context == tagA)
                    A += buffer;
                if (context == tagB)
                    B += buffer;
                if (context == tagC)
                    C += buffer;

            }


        };
    }

}

int main()
{
    string A = "";
    string B = "";
    string C = "";
    string tagA = "";
    string tagB = "";
    string tagC = "";

    cout << "Enter tag A: " << endl;
    cin >> tagA;
    cout << "Etner tag B: " << endl;
    cin >> tagB;
    cout << "Enter tag C: " << endl;
    cin >> tagC;


    string test = "<PartA>This is the first part.<PartB>This part should be second.<>Do not parse this.";
    parse(test, tagA, tagB, tagC, A, B, C);
    cout << "The original string was: " << endl;
    cout << test << endl;
    cout << endl << "The parser output is: " << endl;
    cout << "Token A: " << A << endl;
    cout << "Token B: " << B << endl;
    cout << "Token C: " << C << endl;


}