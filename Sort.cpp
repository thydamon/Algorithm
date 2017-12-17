/*************************************************************************
    > File Name: Sort.cpp
    > Author: Damon
    > Mail: thydamon@gmail.com 
    > Created Time: Wed 06 Dec 2017 07:31:04 PM EST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <malloc.h>

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

int ShellSort(int arr[], int n)
{
	int i,j,gap;

	gap = n/2;

	while (1 <= gap)
	{
		for (i = gap; i < n; i++)
		{
			if (arr[i-gap] > arr[i])
			{
				int tmp = arr[i];
				for (j = i-gap; arr[j] > tmp && j >= 0; j -= gap)
				{
					arr[j+gap] = arr[j];
				}

				arr[j+gap] = tmp;
			}
		}
		gap = gap/2;
	}

	return 0;
}

int Merge(int arr[],int a,int mid,int b)
{
    int i,j,k;
	//int *arr2 = (int *)malloc(b*sizeof(arr));
	int *arr2 = new int[b];

    for (k = 0; k < b; k++) 
	{
        arr2[k] = arr[k]; 
	}

	k = 0;
	i = a;
	j = mid;

	cout << "mid:" << mid << endl;

	while (i < mid && j < b)
	{
		if (arr2[i] < arr2[j])
		{
			arr[k++] = arr2[i++];
		}
		else
		{
			arr[k++] = arr2[j++];
		}
	}

    while (i < mid)
	{
		arr[k++] = arr2[i++];
	}

	while (j < b)
	{
		arr[k++] = arr2[j++];
	}

	// free(arr2);
	delete[] arr2;

    return 0;
}

int MergeSort(int arr[],int a, int b)
{
	if (a < b)
	{
		int mid = (a + b)/2;
		MergeSort(arr,0,mid);
		MergeSort(arr,mid+1,b);
		Merge(arr,0,mid,b);
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
	// InsertSort(arr,10);
	// ShellSort(arr,10);
	PrintSort(arr,10);
	MergeSort(arr,0,10);
	PrintSort(arr,10);
  
	return 0;
}
