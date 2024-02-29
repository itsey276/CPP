#include <iostream>
using namespace std;

class Parent
{
private:

	int gun_safe_code;
	string porn_password;

public:

	string address;

	Parent()
	{
		gun_safe_code = 666;
		porn_password = "SpankMe";
		address = "100 Main Street, Springfield, VA 22151";
	}

	int give_gun() 
	{
		return gun_safe_code;
	}

	string give_password()
	{
		return porn_password;
	}


};

class Child : private Parent
{
public:

	Child()
	{};

	void give()
	{
		cout << address << endl;
		cout << "The gun safe password is: " << give_gun() << endl;
		cout << "My parent's porn passwword is: " << give_password() << endl;


	}

};



int main() 
{
	Child Frezzy;

	Frezzy.give();

	return 0;
}
