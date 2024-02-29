#include <iostream>
using namespace std;
const int Rsize = 3;
const int Csize = 3;

void print(float array[Rsize][Csize]) {
	for (int i = 0; i < Rsize; ++i) {
		for (int j = 0; j < Csize; ++j)
			cout << array[i][j] << " ";
		cout << endl;
	}
}

void swap(float array[Rsize][Csize], int from_row, int to_row) {
	float temp = 0;
	for (int j = 0; j < Csize; ++j) {
		temp = array[from_row][j];
		array[from_row][j] = array[to_row][j];
		array[to_row][j] = temp;
	}
}

int max_pivot(float array[Rsize][Csize], int k, int l) {
	float max_value = array[k][l];
	float max_row = k;
	for (int i = k + 1; i < Rsize; ++i) {
		if (array[i][l] > max_value) {
			max_value = array[i][l];
			max_row = i;
		}
	}
	return max_row;
}

void reduce_row(float array[Rsize][Csize], int k, int l) {
	float factor = 0;
	for (int i = k + 1; i < Rsize; ++i) {
		factor = array[i][l] / array[k][l];
		for (int j = l; j < Csize; ++j)
			array[i][j] = array[i][j] - factor * array[k][j];
	}
}

int elimination(float array[Rsize][Csize]) {
	int k = 0;
	int l = 0;
	int swaps = 0;
	int maxRow = 0;
	while ((k < Rsize) && (l < Csize)) {
		maxRow = max_pivot(array, k, l);
		if (maxRow > k) {
			swap(array, k, maxRow);
			swaps += 1;
		}
		if (array[k][l] != 0) {
			reduce_row(array, k, l);
			k += 1;
			l += 1;
		}
		else
			l += 1;
	}

	return swaps;
}


int main()
{
	int swaps = 0;
	float array[Rsize][Csize] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	print(array);
	cout << "-----" << endl;
	swaps = elimination(array);
	print(array);
	cout << "Swaps: " << swaps << endl;

	return 0;
}