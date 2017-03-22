#include"Bubblesort.h"
#include<iostream>
using namespace std;

void main()
{
	Bubblesort s;

	int arr[6] = { 2,4,1,6,5,3 };

	cout << "[퀵소트 전]" << endl;
	for (int i = 0; i <= 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	s.QuickSort(arr, 0, 5);
	
	cout << "[퀵소트 후]" << endl;
	for (int i = 0; i <= 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int arr2[] = { 2,4,5,6,7,1,2,4,5,2,6,1 };
	cout << "[버블소트 전]" << endl;

	for (int i = 0; i < sizeof(arr2) / sizeof(int); ++i)
	{
		cout << arr2[i] << " ";
	}

	s.BubbleSort(arr2, sizeof(arr2)/sizeof(int));

	cout << "[버블소트 후]" << endl;
	for (int i = 0; i < sizeof(arr2) / sizeof(int); ++i)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
}