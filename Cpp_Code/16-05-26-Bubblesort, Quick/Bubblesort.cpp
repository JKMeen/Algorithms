#include "Bubblesort.h"

void Bubblesort::Swap(int & ref1, int & ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int Bubblesort::Partition(int arr[], int left, int right)
{
	int pivot = arr[left]; //선택한 숫자(제일 왼쪽 숫자)
	int low = left+1, high = right; // 인덱스 값을 나타내기 때문에 위치정보를 줌 / left +1은 비교할 숫자이기 때문에 +1해줌

	while (low <= high)
	{
		while (pivot >= arr[low] && low<=right) { //교차했을 때 끝낼 것이기 때문
			low++;
		}
		while (pivot <= arr[high] && high>left) {
			high--;
		}

		if(low<=high)
			Swap(arr[low], arr[high]);
	}
	Swap(arr[left], arr[high]);
	return high;
}

void Bubblesort::BubbleSort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr[j], arr[j + 1]);
		}
	}
}

void Bubblesort::QuickSort(int arr[], int left, int right)
{
	if (left >= right)
		return;
	int mid = Partition(arr, left, right);
	QuickSort(arr, left, mid - 1);
	QuickSort(arr, mid + 1, right);
}