#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void getmatrix(vector<vector<float>>& matrix)
{
	matrix =
	{
		{1, 2, 4, 1 },
		{4, 5, 6, 2 },
		{7, 8, 9, 3 },
		{1, 1, 1, 1 }

	};

}

void printmatrix(vector<vector<float>>& matrix)
{
	for (vector<float> vect1D : matrix)
	{
		for (float x : vect1D)
		{
			cout << setw(10) << x << " ";

		}
		cout << endl;
	}
}

void swaprow(vector<vector<float>>& matrix, int a, int b, vector<vector<float>>& Pmatrix)
{
	vector<float> swap;
	swap = matrix[a];
	matrix[a] = matrix[b];
	matrix[b] = swap;

	swap = Pmatrix[a];
	Pmatrix[a] = Pmatrix[b];
	Pmatrix[b] = swap;

}

void madd(vector<vector<float>>& matrix, float c, int a, int b)
{
	int cols = matrix[0].size();
	for (int i = 0; i < cols; i++)
		matrix[a][i] = matrix[a][i] + c * matrix[b][i];

}

void reduce(vector<vector<float>>& matrix, int pivotR, int pivotC)
{
	float c;
	int Rsize = matrix.size();

	for (int i = pivotR + 1; i < Rsize; i++)
	{ 
		c = -matrix[i][pivotC] / matrix[pivotR][pivotC];
		if (c != 0) madd(matrix, c, i, pivotR);
	}

}

void reduce_back(vector<vector<float>>& matrix, int pivotR, int pivotC)
{
	float c;
	int Rsize = matrix.size();

	for (int i = 1; i <= pivotR; i++)
	{
		int index = pivotR - i;
		c = -matrix[index][pivotC] / matrix[pivotR][pivotC];
		if (c != 0) madd(matrix, c, index, pivotR);
	}

}

void Gauss(vector<vector<float>>& matrix, vector<vector<float>>& pmatrix)
{
	int k = -1;
	int l = -1;
	int LMAX = matrix[0].size();
	int KMAX = matrix.size();
	bool pivot = false;
	int pivotR = 0;



	while (k < (KMAX - 1))
	{
		++k;
		pivot = false;

		while ((!pivot) && (l < (LMAX - 1)))
		{
			++l;
			for (int i = k; i < KMAX; i++)
				if (matrix[i][l] != 0)
				{
					pivot = true;
					pivotR = i;
					break;
				}

			if (pivot && (pivotR > k)) swaprow(matrix, k, pivotR, pmatrix);

		}

		reduce(matrix, k, l);

	};

}


void initswap(vector<vector<float>>& swap)
{
	for (int i = 0; i < swap.size(); i++)
		for (int j = 0; j < swap[0].size(); j++)
			if (i == j) swap[i][j] = 1;
			else swap[i][j] = 0;
}

int Mrank(vector<vector<float>>& matrix)

{
	int sum = 0;
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[0].size(); j++)
			if (i == j)
				if (matrix[i][j] != 0)
					++sum;

	return sum;
}

float determinant(vector<vector<float>>& matrix)  // takes a row reduced matrix
{
	int maxR = 0;
	int index = 0;
	float det = 1;

	if (matrix.size() > matrix[0].size())
		maxR = matrix[0].size();
	else maxR = matrix.size();

	for (int i = 0; i < maxR; i++)
	{
		det *= matrix[i][i];
	}

	return det;

}

void M_Analyze(vector<vector<float>>& matrix)

{
	int rows = matrix.size();
	int columns = matrix[0].size();
	int rank = Mrank(matrix);
	float det = 1;

	det = determinant(matrix);
	cout << "rows: " << rows << endl;
	cout << "columns: " << columns << endl;
	cout << "rank: " << rank << endl;

	if ((columns > rank) && (rows > rank))
		cout << "This matrix is missing both column and row ranks. Ax = b may have no solutions or infinitely many solutions." << endl;
	
	if ((rank == rows) && (rows == columns))
		cout << "This is a square invertible matrix! Ax = b has exactly one solution." << endl;
	
	if ((rank == rows) && (rows < columns))
		cout << "This matrix has full row rank but free columns. Ax = b has infinitely many solutions!" << endl;
	
	if ((rank == columns) && (columns < rows))
		cout << "This matrix has full column rank but extra rows. Ax = b may have no solutions or 1 solution." << endl;

	if (rows == columns)
		cout << "The determinant is " << det << endl;
	
}

void rref_steps(vector<vector<float>>& matrix)  // takes a row reduced matrix
{
	int maxR = 0;
	int index = 0;

	if (matrix.size() > matrix[0].size())
		maxR = matrix[0].size();
	else maxR = matrix.size();

	for (int i = 1; i < maxR; i++)
	{
		index = maxR - i;
		reduce_back(matrix, index, index);
	}

	float divisor = 1;

	for (int i = 0; i < maxR; i++)
	{
		if (matrix[i][i] != 0)
		{
			divisor = matrix[i][i];
			for (int j = 0; j < matrix[0].size(); j++)
				if (matrix[i][j] != 0) matrix[i][j] = matrix[i][j] / divisor;
		}
	}

}



int main()
{
	vector<vector<float>> matrix(3, vector<float>(3));
	vector<vector<float>> swap(3, vector<float>(3));

	getmatrix(matrix);
	initswap(swap);
	int RR = matrix.size();
	int CC = matrix[0].size();

	cout << "Original Matrix: " << endl;
	printmatrix(matrix);
	cout << endl;
	
	Gauss(matrix, swap);
	cout << "Row Echelon Form: " << endl;
	printmatrix(matrix);
	cout << endl;
	cout << "Swap matrix: " << endl;
	printmatrix(swap);
	cout << endl;
	
	rref_steps(matrix);
	cout << "Row Reduced Echelon Form:" << endl;
	printmatrix(matrix);
	cout << endl;
	M_Analyze(matrix);

	return 0;


}


