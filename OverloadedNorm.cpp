#include <iostream>
using namespace std;
const int vectorlength = 4;

float Dot(float vector1[vectorlength], float vector2[vectorlength]) // standard inner product
{
	float DotSum = 0;
	for (int index = 0; index < vectorlength; ++index)
			DotSum = DotSum + vector1[index] * vector2[index];

	return DotSum;
}

float Dot(float vector[vectorlength])      // (overloaded) the inner product of a vector with itself 
{
	return Dot(vector, vector);
}

float norm(float vector[vectorlength])     // standard norm definition of a vector
{
	return sqrt(Dot(vector));              // the argument of the square root is guaranteed to be positive
}

float norm(float vector1[vectorlength], float vector2[vectorlength]) // (overloaded) "projection norm" (p) 
{                                                                    
	return (Dot(vector1, vector2) / Dot(vector2));
}

int printvector(float vector[vectorlength]) // io operations
{
	std::cout << "(x y ...) = " << endl;
	for (int index = 0; index < vectorlength; ++index)
		std::cout << vector[index] << ", ";
	std::cout << endl;

	return 0;
}

int getvector(float (&vector)[vectorlength]) // io operations
{
	std::cout << "Enter the coordinates of a vector (x, y, ... n) in R(" << vectorlength << "): " << endl;
	for (int index = 0; index < vectorlength; ++index)
		cin >> vector[index];

	return 0;
}

int main()
{
	
	float Pvector[vectorlength] = {};
	float Avector[vectorlength] = {};
	float Bvector[vectorlength] = {};

	std::cout << "Enter two vectors (A and B): " << endl;
	getvector(Avector);
	getvector(Bvector);

	std::cout << "Vector A is:" << endl;
	printvector(Avector);
	std::cout << "Vector B is:" << endl;
	printvector(Bvector);

	std::cout << "The length of Vector A is: " << norm(Avector) << endl;
	std::cout << "The length of Vector B is: " << norm(Bvector) << endl;

	float Pcoefficient = norm(Avector, Bvector);

	for (int index = 0; index < vectorlength; ++index)
		Pvector[index] = Pcoefficient * Bvector[index];

	std::cout << "The projection of Vector A onto B ";
	printvector(Pvector);
	std::cout << "The length of this projected vector is: " << norm(Pvector) << endl;

	return 0;
}