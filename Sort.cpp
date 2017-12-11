/*************************************************************************
    > File Name: Sort.cpp
    > Author: Damon
    > Mail: thydamon@gmail.com 
    > Created Time: Wed 06 Dec 2017 07:31:04 PM EST
 ************************************************************************/

#include <iostream>
using namespace std;

int PrintSort(int arr[],int n);

int BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n-1; j >= i; j--)
		{
			if (arr[j] < arr[j-1])
			{
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}

	return 0;
}

int SelectSort(int arr[], int n)
{
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				min = j;
			}
		}

		if (min != i)
		{
			int tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp;
		}
	}

	return 0;
}

int InsertSort(int arr[], int n)
{
	int i,j;
#if 0
	for (i = 0; i < n; i++)
	{
		if (arr[i-1] > arr[i])
		{
			int tmp = arr[i];

			for (j = i-1; arr[j]>tmp && j >= 0; j--)
			{
				arr[j+1] = arr[j];
			}

			arr[j+1] = tmp;
		}
	}
#endif

	for (i = 0; i < n-1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			int tmp = arr[i+1];

			for (j = i; arr[j] > tmp && j >= 0; j--)
			{
				arr[j+1] = arr[j];
			}

			arr[j+1] = tmp;
		}
	}

	return 0;
}

int PrintSort(int arr[],int n)
{
    for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << std::endl;

	return 0;
}

int main()
{
	int arr[10] = {1,3,5,4,2,7,8,9,0,6};

	// BubbleSort(arr,10);
	// SelectSort(arr,10);
	InsertSort(arr,10);
	PrintSort(arr,10);
  
	return 0;
}
