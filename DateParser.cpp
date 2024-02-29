#include <iostream>
#include <string>

using namespace std;


void parse(const string& input, int& imonth, int& iday, int& iyear)
{

	int context = 0;
	char buffer = '!';
	string month = "";
	string day = "";
	string year = "";

	for (string::const_iterator charPos = input.cbegin(); charPos != input.cend(); ++charPos)
	{
		buffer = *charPos;
		if (buffer == '/')
			++context;
		else
		{
			if (context == 0) month.append(1, buffer);
			if (context == 1) day.append(1, buffer);
			if (context == 2) year.append(1, buffer);
		};
	}

	imonth = stoi(month);
	iday = stoi(day);
	iyear = stoi(year);
}

int main()
{
	string date("07/30/2024");
	int month = 0;
	int day = 0;
	int year = 0;

	parse(date, month, day, year);

	cout << "Date as string: " << date << endl;

	cout << "The month is: " << month << endl;
	cout << "The day is: " << day << endl;
	cout << "The year is: " << year << endl;

}