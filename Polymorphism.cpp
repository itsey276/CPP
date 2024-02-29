#include <iostream>
#include <iomanip>

using namespace std;

class Matrix
{
public:
	int m; // number of rows
	int n; // nummber of columns
	int Entry[3][3]; // 3 x 3 array (allocate maximum size)
	
	Matrix() // default constructor creates a 3x3 identity matrix
	{
		m = 3;
		n = 3;
		for (int i_index = 0; i_index < 3; ++i_index)
			for (int j_index = 0; j_index < 3; ++j_index)
				if (i_index == j_index) Entry[i_index][j_index] = 1;
				else Entry[i_index][j_index] = 0;
	}
};

class vector : public Matrix
{
public:

	
	vector() // default constructor
	{
		n = 1; // set number of columns to 1
	}

	float length()
	{
		int nsum = 0;
		for (int i_index = 0; i_index < m; ++i_index)
			nsum = nsum + Entry[i_index][1] * Entry[i_index][1];
		return sqrt(nsum);
	}

};

void mmult(Matrix &AMatrix, Matrix &BMatrix)
{
	if (AMatrix.n != BMatrix.m)
	{
		cout << "Error - mismatched matrix dimensions!" << endl;
	}
	else

		for (int i_index = 0; i_index < BMatrix.m; ++i_index)
		{
			for (int j_index = 0; j_index < AMatrix.n; ++j_index)
			{
				cout << AMatrix.Entry[i_index][j_index] * BMatrix.Entry[j_index][i_index] << setw(10);
			}
			cout << endl;
		}
}

void msub(Matrix &AMatrix, Matrix &BMatrix)
{
	if (AMatrix.n != BMatrix.n || AMatrix.m != BMatrix.m)
	{
		cout << "Error - mismatched matrix dimensions!" << endl;
	}
	else

		for (int i_index = 0; i_index < BMatrix.n; ++i_index)
		{
			for (int j_index = 0; j_index < AMatrix.n; ++j_index)
			{
				cout << AMatrix.Entry[i_index][j_index] - BMatrix.Entry[i_index][j_index] << setw(10);
			}
			cout << endl;
		}
}

void madd(Matrix &AMatrix, Matrix &BMatrix)
{
	if (AMatrix.n != BMatrix.n || AMatrix.m != BMatrix.m)
	{
		cout << "Error - mismatched matrix dimensions!" << endl;
	}
	else

		for (int i_index = 0; i_index < BMatrix.n; ++i_index)
		{
			for (int j_index = 0; j_index < AMatrix.n; ++j_index)
			{
				cout << AMatrix.Entry[i_index][j_index] + BMatrix.Entry[i_index][j_index] << setw(10);
			}
			cout << endl;
		}
}