#include <iostream>
using namespace std;

struct Pressure
{
	double Pascals;
	Pressure(long double pressure) : Pascals(pressure) {}
};

Pressure operator"" _kPA(long double kpa)
{
	return Pressure(kpa * 1000);
}

Pressure operator "" _mmHG(long double mmhg)
{
	return Pressure(mmhg * 133.322);
}

Pressure operator "" _Atm(long double atm)
{
	return Pressure(atm * 101325);
}

Pressure operator "" _Bar(long double bar)
{
	return Pressure(bar * 100000);
}

Pressure operator "" _PSI(long double psi)
{
	return Pressure(psi * 6894.76);
}

Pressure operator "" _BA(long double barye)
{
	return Pressure(barye * 0.1);
}

Pressure operator "" _Pa(long double pascals)
{
	return Pressure(pascals);
}


int main()
{
	Pressure P1 = 1.0_Atm;
	Pressure P2 = 101.325_kPA;
	Pressure P3 = 760.0_mmHG;
	Pressure P4 = 1.01325_Bar;
	Pressure P5 = 14.6959_PSI;
	Pressure P6 = 1.013e6_BA;

	
	cout << "P1 is " << P1.Pascals << " Pa" << endl;
	cout << "P2 is " << P2.Pascals << " Pa" << endl;
	cout << "P3 is " << P3.Pascals << " Pa" << endl;
	cout << "P4 is " << P4.Pascals << " Pa" << endl;
	cout << "P5 is " << P5.Pascals << " Pa" << endl;
	cout << "P6 is " << P6.Pascals << " Pa" << endl;

	
	return 0;
}