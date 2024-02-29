#include<iostream>
using namespace std;
const int arraysize = 10;

int GetData(int (&nums)[arraysize])
{
	cout << "Enter " << arraysize << " integers to be sorted." << endl;
	for (int index = 0; index < arraysize; ++index)
	{
		cout << "Enter integer: " << endl;
		cin >> nums[index];
	}
	return 0;
}

int PrintData(int* (&pnums)[arraysize])
{
	cout << "The processed data is:" << endl;
	for (int index = 0; index < arraysize; ++index)
		cout << index << ": " << *pnums[index] << endl;
	
	return 0;
}

int SetPointers(int (&nums)[arraysize], int* (&pnums)[arraysize])
{
	for (int index = 0; index < arraysize; ++index)
		pnums[index] = &nums[index]; // initialize each pointer to the corresponding sort value address
	return 0;
}

int SortPointers(int* (&pnums)[arraysize])
{
	int* swapvalue = {};
	bool swapped = 0;
	int a = 0;
	int b = 0;

	do
	{
	swapped = 0;   // reset swapped flag to False
	for (int index = 0; index < (arraysize - 1); ++index)
		{
		a = *pnums[index];
		b = *pnums[index + 1];
		if (a > b)
			{
			swapvalue = pnums[index];
			pnums[index] = pnums[index + 1];
			pnums[index + 1] = swapvalue;
			swapped = 1;  // if a swap procedure was performed, change the swapped flag to True
			}
		}
	} while (swapped == 1);

	return 0;
}

int main()
{
	int MyList[arraysize] = {};
	int* MyPointers[arraysize] = {};

	GetData(MyList);
	SetPointers(MyList, MyPointers);
	
	cout << "Unsorted List:" << endl;
	PrintData(MyPointers);

	SortPointers(MyPointers);

	cout << "Sorted List:" << endl;
	PrintData(MyPointers);

	return 0;
}

