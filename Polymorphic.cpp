#include <iostream>
using namespace std;

class Human
{
public:
	string first_name;
	string last_name;
	enum biologicalsex 
	{
		male = 0,
		female

	};
	enum genderidentity
	{
		Male = 0,
		Female,
		Nonbinary

	};

	biologicalsex sex;
	genderidentity gender;


	virtual void Hello() 
	{
		cout << "Hello, my name is " << first_name << " " << last_name << ", but you can call me " << first_name << "." << endl;
	}

	Human(string first, string last) // default constructor
	{
		first_name = first;
		last_name = last;
	}

	Human() 
	{
		first_name = "John";
		last_name = "Doe";
		sex = male;
		gender = Male;
	}

};

class Man :public Human
{
public:
	
	Man(string first, string last, int bio)
	{
		first_name = first;
		last_name = last;
		if (bio == 0)
			sex = male;
		else sex = female;

	}
	void Hello()
	{
		cout << "Hello, my name is " << first_name << " " << last_name << ", but you can call me " << first_name << "." << endl;
		cout << "My pronouns are he / him." << endl;
		if (sex == female)
			cout << "However, I was born biologically female." << endl;
	}
};

class Woman :public Human
{
public:
	
	Woman(string first, string last, int bio)
	{
		first_name = first;
		last_name = last;
		gender = Female;
		if (bio == 0)
			sex = male;
		else sex = female;
	}

	void Hello()
	{
		cout << "Hello, my name is " << first_name << " " << last_name << ", but you can call me " << first_name << "." << endl;
		cout << "My pronouns are she / her." << endl;
		if (sex == male)
			cout << "However, I was born biologically male." << endl;
	}
};

class Other :public Human
{
public:
	
	Other(string first, string last, int bio)
	{
		first_name = first;
		last_name = last;
		gender = Nonbinary;
		if (bio == 0)
			sex = male;
		else sex = female;
	}

	void Hello()
	{
		cout << "Hello, my name is " << first_name << " " << last_name << ", but you can call me " << first_name << "." << endl;
		cout << "My pronouns are they / them." << endl;
		if (sex == male)
			cout << " I was born biologically male, but I do not identify with a gender." << endl;
		else cout << "I was born biologically female, but I do not identify with a gender." << endl;
	}
};

int main()
{
	Human Donald("Donald", "Trump");
	Man Joe("Joe", "Biden", 0);
	Woman Dylan("Dylan", "Mulvaney", 0);
	Other Bella("Bella", "Ramsey", 1);

	Donald.Hello();
	Joe.Hello();
	Dylan.Hello();
	Bella.Hello();

	return 0;

}