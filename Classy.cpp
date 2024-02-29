#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Body
{
public:
	string name;
	string parent;
	double parentmass;        // kg
	double parentdistance;    // meters
	double mass;              // kg
	double radius;            // meters
	double G = 6.674e-11;     // N⋅m2⋅kg-2

	double escapevelocity()   //escape velocity from the surface)
	{
				return sqrt(2 * G * mass / radius);
	}

	double orbitvelocity()    //velocity for a minimum-sized circular orbit
	{
				return escapevelocity() / sqrt(2);
	}


	double rochelimit()       // distance within which a large body held together by gravity will break up
	{
				return radius * cbrt(2 * parentmass / mass);

	}

	double hilllimit()        // distance beyond which any orbit is unstable
	{
				return parentdistance * cbrt(mass / (3 * (mass + parentmass)));
		
	}

	Body()                    // default constructor
	{
		name = "Earth";
		parent = "Sun";
		parentmass = 1.989e30;          // in kgs
		parentdistance = 1.496e11;      // in meters
		mass = 5.972e24;                // in kgs
		radius = 6.371e6;               // in meters
	} 

};

int do_the_statistics(Body MyPlanet)
{
	cout << "The body, " << MyPlanet.name << ", has a mass of " << MyPlanet.mass << " kg and a radius of " \
		<< MyPlanet.radius << " meters." << endl;
	cout << MyPlanet.name << " orbits: " << MyPlanet.parent << endl;
	cout << "Escape velocity from its surface is " << MyPlanet.escapevelocity() << " m/s." << endl;
	cout << "A minimum circular orbit around " << MyPlanet.name << " requires a speed of " << MyPlanet.orbitvelocity() \
		<< " m/s." << endl;
	cout << "Any orbit beyond a distance of " << MyPlanet.hilllimit() << " meters would be unstable." << endl;
	cout << "Any extended object closer than " << MyPlanet.rochelimit() << " meters is subject to destruction by tidal forces." \
		<< endl;
	return 0;
}

Body Get_Body()
{
	Body MyPlanet;
	
	cout << "Enter characteristics of a new body :" << endl;
	cout << "Enter the name of this body: " << endl;
	cin >> MyPlanet.name;
	cout << "Enter the mass of the object (in Kgs): " << endl;
	cin >> MyPlanet.mass;
	cout << "Enter the radius of the object (in meters): " << endl;
	cin >> MyPlanet.radius;
	cout << "Enter the name of the parent body: " << endl;
	cin >> MyPlanet.parent;
	if (MyPlanet.parent != "Sun")
	{
		cout << "Enter the mass of the parent body (in Kgs): " << endl;
		cin >> MyPlanet.parentmass;
		cout << "Enter the distance of parent body (in meters): " << endl;
		cin >> MyPlanet.parentdistance;
	}

	return MyPlanet;
}

int main()
{
	Body MyPlanet;                 // create the object MyPlanet of type Body

	cout << "Default body characteristics: " << endl;
	do_the_statistics(MyPlanet);   // display default values 
	cout << endl;

	MyPlanet = Get_Body();         // get values from user input 
	do_the_statistics(MyPlanet);   // calculate new values      
}