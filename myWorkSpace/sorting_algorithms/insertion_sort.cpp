#include<iostream>

using namespace std;

void insertion_sort(unsigned int arr[], unsigned int len)
{
	cout << "In insertion_sort \n";
	unsigned int i,j; 								// Counters
	for (i=1; i<len; i++)
	{
		j=i;
		while((j>0) && (arr[j] < arr[j-1]))
		{
			swap(arr[j], arr[j-1]);
			j=j-1;
		}
	cout << " Value of i = "<< i << "\n";
	for (unsigned int i=0; i<len; i++)
	{
		cout << arr[i] << " ; ";
	}
	cout << "\n";
	}
}

int main()
{
	unsigned int inputArr[] = {99, 18, 25, 20, 101, 5};
        unsigned int arrLen = sizeof(inputArr)/sizeof(inputArr[0]);
	cout << "Length of array is: "<< arrLen << "\n";
	insertion_sort(inputArr, arrLen);
	cout << "############################## \n";
	cout << "Sorted array \n";
	for (unsigned int i=0; i<arrLen; i++)
	{
		cout << inputArr[i] << " ; ";
	}
	cout << "\n";

}
