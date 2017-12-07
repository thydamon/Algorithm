/*************************************************************************
    > File Name: Sort.cpp
    > Author: Damon
    > Mail: thydamon@gmail.com 
    > Created Time: Wed 06 Dec 2017 07:31:04 PM EST
 ************************************************************************/

#include <iostream>
using namespace std;

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
	SelectSort(arr,10);
	PrintSort(arr,10);
  
	return 0;
}
