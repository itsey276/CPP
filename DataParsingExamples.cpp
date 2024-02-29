#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>

using namespace std;


// Input file example :

// 12 : 49 : 00

// Store :

//   hrs = 12
//    mins = 59
//    sec = 00


void match_pattern()
{
    const std::regex time_regex("(\\d|[0,1]\\d|2[0-3]):([0-5]\\d):([0-5]\\d)");
    std::smatch time_match;
    std::string line;

    while (std::getline(std::cin, line))
    {
        if (std::regex_match(line, time_match, time_regex))
        {
            int hours = std::stoi(time_match[1]);
            int minutes = std::stoi(time_match[2]);
            int seconds = std::stoi(time_match[3]);
            std::cout << "h=" << hours << " m=" << minutes << " s=" << seconds << std::endl;
        }
        else
        {
            std::cout << "Invalid time: " << line << std::endl;
        }
    }

}

int pattern2()
{
    {
        int h, m, s;
        std::cin >> h;
        std::cin.ignore(1) >> m;
        std::cin.ignore(1) >> s;
        std::cout << h << ':' << m << ':' << s << std::endl;
        return 0;
    }

}

void skip_colon(const char* file)
{

    // see https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/ for reference
    
    ifstream myFile;
    myFile.open(file, ios_base::in);
    for (std::string line; std::getline(myFile, line);)
    {
        // turn the line into a stream
        std::istringstream f(line);

        std::getline(f, line, ':'); // skip past ':'

        // read all the numbers one at a time
        for (int v; f >> v;)
            std::cout << v << ' ';

        std::cout << '\n';
    }

}


int main()
{
	return 0;

}