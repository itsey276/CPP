#include <iostream>
using namespace std;

class Animalia
{
public:
	bool sick;

	Animalia()
	{
		sick = false;
	}

	virtual void treat()
	{
		if (sick)
			cout << "Euthanizing the animal." << endl;
	}

};

class Mammalia : public Animalia
{
public:

	Mammalia()
	{
		sick = false;

	}

	void treat()
	{
		if (sick)
			cout << "Giving medicine to the mammal." << endl;
	}

};

class Rhinoceros: public Mammalia
{

public:

	Rhinoceros()
	{
		sick = false;

	}

	void treat()
	{
		if (sick)
			cout << "Performing an operation on the rhinoceros." << endl;
	}

};


void Classify(Animalia* creature)
{
	Animalia* animal = dynamic_cast <Animalia*>(creature);
	if (animal)
		cout << "This creature is an animal." << endl;

	Mammalia* mammal = dynamic_cast <Mammalia*>(creature);
	if (mammal)
		cout << "This creature is a mammal." << endl;
	
	Rhinoceros* rhino = dynamic_cast <Rhinoceros*>(creature);
		if (rhino)
		cout << "This creature is a rhinoceros." << endl;
}

void Evaluate(Animalia* creature)
{
	if (creature->sick)
		creature->treat();
}


int main()
{
	Rhinoceros Joe;
	Mammalia lemur;
	Animalia snake;

	Joe.sick = true;
	lemur.sick = true;
	snake.sick = true;

	cout << endl << "First patient: " << endl << endl;
	Classify(&Joe);
	Evaluate(&Joe);


	cout << endl <<  "Second patient: " << endl << endl;
	Classify(&lemur);
	Evaluate(&lemur);

	cout << endl << "Third patient: " << endl << endl;
	Classify(&snake);
	Evaluate(&snake);

	
};



