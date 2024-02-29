#include <iostream>
using namespace std;

	
	class Dog
	{
	public:

		virtual void Bark()
		{
			cout << "Woof! Woof!" << endl;
		}
	};

	class Chihuahua :public Dog
	{
	public:
		void Bark()
		{
			cout << "Yip! Yip!" << endl;
		}
	};

	class Mutt :public Dog
	{
	public:
		void Bark()
		{
			cout << "Arg! Arg!" << endl;
		}
	};

	int main()
	{
		Mutt* Mydog = new Mutt();
		Mydog->Bark();
		cout << endl;
		

		Dog* Somedog = new Dog();
		Somedog->Bark();
		cout << endl;

		Chihuahua* straydog = new Chihuahua();
		straydog->Bark();
		cout << endl;

		return 0;
	}