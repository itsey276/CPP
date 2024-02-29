#include <iostream>
#include <string>
#include <vector>
const int array_size = 3;

using namespace std;

void print_array(const int array[array_size][array_size]) {
	for (int i = 0; i < array_size; ++i) {
		for (int j = 0; j < array_size; ++j) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void change_value(int array[array_size][array_size]) {
	array[1][1] = 0;
}

void clone_array(int array_source[array_size][array_size], int array_destination[array_size][array_size]) {
	for (int i = 0; i < array_size; ++i)
		for (int j = 0; j < array_size; ++j)
			array_destination[i][j] = array_source[i][j];
}


int main()
{
	int array[array_size][array_size] = { {1, 2, 3},
									{4, 5, 6},
									{7, 8, 9} };

	int new_array[array_size][array_size];
	print_array(array);
	cout << "============" << endl;
	clone_array(array, new_array);
	print_array(new_array);
	cout << "============" << endl;
	change_value(new_array);
	print_array(array);
	cout << "============" << endl;
	print_array(new_array);
	cout << "============" << endl;
	cout << "array address: " << array << endl;
	cout << "address of 1st row: " << array[0] << endl;
	cout << "first value in 1st row (in array syntax): " << *array[0] << endl;
	cout << "equivalently (in pointer syntax): " << *(*array) << endl;
	cout << "address of 2nd row: " << (*(array + 1)) << endl;
	cout << "value at first address in 2nd row: " << *(*(array + 1)) << endl;

	return 0;

}