#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;

template <typename T> // Type must support real numbers (e.g., float, doouble, etc.)
class Vector
{
public:
	vector<T> X;
	size_t size;

	Vector() // default constructor
	{
		X = {};
		size = 0;
	}

	Vector(vector<T>* input) // Copy Constructor
	{
		size = input.size();

		for (int i = 0; i < size; ++i)
		{
			X.push_back(*input[i]);
		}
	}

	T dot(Vector* B) // inner product
	{

		unsigned int a_size = X.size();
		unsigned int b_size = B->X.size();

		T dotproduct = 0;
		assert(a_size == b_size); // throws a message if sizes are mismatched
		if (a_size == b_size) 
			for (int i = 0; i < a_size; ++i)
				dotproduct += (X[i]) * (B->X[i]);

		return dotproduct;
	}

	T length()
	{
		unsigned int size = X.size();
		T sum = 0;

		if (size > 0)
			for (int i = 0; i < size; ++i)
				sum += (X[i]) * (X[i]);
		else return 0;

		return sqrt(sum);
	}

	void print_v()
	{
		int max = X.size();

		if (max > 0)
			for (int i = 0; i < (max - 1); ++i)
				cout << setw(15) << X[i] << ", ";
		cout << setw(15) << X[max - 1] << "." << endl;
	}

	void plus(Vector* B) // vector addition
	{

		unsigned int a_size = X.size();
		unsigned int b_size = B->X.size();

		assert(a_size == b_size); // throws a message if sizes are mismatched
		if (a_size == b_size)  // check for matching dimensions
			for (int i = 0; i < a_size; ++i)
				X[i] += B->X[i];
	}

	void minus(Vector* B) // vector subtraction
	{

		unsigned int a_size = X.size();
		unsigned int b_size = B->X.size();

		assert(a_size == b_size); // throws a message if sizes are mismatched
		if (a_size == b_size)
			for (int i = 0; i < a_size; ++i)
				X[i] -= B->X[i];
	};

	void smult(T c) // scalar multiplication 
	{

		unsigned int a_size = X.size();

		for (int i = 0; i < a_size; ++i)
			X[i] *= c;

	};

	void projection(Vector* A, Vector* B) 
	{

		unsigned int a_size = A->X.size();
		unsigned int b_size = B->X.size();
		T numerator = 0;
		T denom = 0;
		X = {};

		numerator = A->dot(B);
		denom = B->length() * B->length();

		assert(a_size == b_size); // throws a message if sizes are mismatched
		if (a_size == b_size) 
				for (int i = 0; i < a_size; ++i)
					X.push_back(B->X[i] * numerator / denom);

	}

	void normalize()
	{
	    T norm = length();
		unsigned int size = X.size();

		for (int i = 0; i < size; ++i)
			X[i] /= norm;
	}


};

void DisplayVectors(Vector<float>* A, Vector<float>* B, Vector<float>* C)

{
	A->print_v();
	cout << endl;
	B->print_v();
	cout << endl;
	C->print_v();
	cout << endl;

};

void Orthogonalize(Vector<float>* A, Vector<float>* B, Vector<float>* C)
{

	Vector<float> P;
	P.projection(B, A);
	B->minus(&P);
	P.projection(C, A);
	C->minus(&P);
	P.projection(C, B);
	C->minus(&P);

	A->normalize();
	B->normalize();
	C->normalize();
}

void GetVectors(Vector<float>* A, Vector<float>* B, Vector<float>* C)
{
	vector<float> a = { 1, -1, 1, -1 };
	vector<float> b = { 1, 1, 1, 1 };
	vector<float> c = { 1, 0, 0, 1 };
	A->X = a;
	B->X = b;
	C->X = c;

}

	int main()
	{

		Vector<float> A; Vector<float> B; Vector<float> C;
		GetVectors(&A, &B, &C);
		cout << "Original Vectors: " << endl;
		DisplayVectors(&A, &B, &C);

		Orthogonalize(&A, &B, &C);
		cout << "Orthogonalized Vectors: " << endl;
		DisplayVectors(&A, &B, &C);


	}
