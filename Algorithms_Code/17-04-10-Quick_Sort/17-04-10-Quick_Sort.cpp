#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

void Swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int Partition(int A[], int low, int high){
	int base = A[high];
	int i = low;

	for (int j = low; j < high; j++)
	if (A[j] <= base)
		Swap(A[i++], A[j]);

	Swap(A[i], A[high]);
	return i;
}

void QuickSort(int A[], int low, int high){
	int mid;
	if (low < high){
		mid = Partition(A, low, high);
		QuickSort(A, low, mid-1);
		QuickSort(A, mid + 1, high);
	}
}

void main(){
	srand((unsigned)time(NULL));
	int a[10];

	printf("[ ");
	for (int i = 0; i<10; i++){
		a[i] = rand() % 100;
		printf("%2.d ", a[i]);
	} printf(" ] / [START]\n\n");

	QuickSort(a, 0, N);

	printf("[ ");
	for (int i = 0; i <= N; i++){
		printf("%2.d ", a[i]);
	} printf(" ] / [END]\n");

}