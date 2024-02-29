#include <iostream>
using namespace std;

int ComplexMultiply();
int GetVectors();
int PrintResult();
float vectorA[2] = {};
float vectorB[2] = {};
float output[2] = {};

int main()
{
	GetVectors();
	ComplexMultiply();
	PrintResult();
	return 0;
}

int GetVectors()
{
	cout << "Enter the real part of number 1: " << endl;
	cin >> vectorA[0];
	cout << endl;
	cout << "Enter the imaginary part of number 1: " << endl;
	cin >> vectorA[1];
	cout << endl;
	cout << "Enter the real part of number 2: " << endl;
	cin >> vectorB[0];
	cout << endl;
	cout << "Enter the imaginary part of number 2: " << endl;
	cin >> vectorB[1];

	return 0;
}


int ComplexMultiply()
{
	output[0] = vectorA[0] * vectorB[0] - vectorA[1] * vectorB[1]; // the real part of the output
	output[1] = vectorA[1] * vectorB[0] + vectorA[0] * vectorB[1]; // the imaginary part of the output
	return 0;
}

int PrintResult()
{
	cout << "Multiplying " << vectorA[0] << " + (" << vectorA[1] << ")i by " << vectorB[0] << " + (" << vectorB[1] << ")i results in:" << endl;
	cout << output[0] << " + (" << output[1] << ")i" << endl;
	return 0;
}