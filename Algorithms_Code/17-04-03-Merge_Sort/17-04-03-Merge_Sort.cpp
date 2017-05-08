#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

void Merge(int A[], int low, int mid, int high){
	int B[N+1];
	int LeftPtr, RightPtr, BufPtr;

	LeftPtr = low; RightPtr = mid + 1; BufPtr = low;
	while (LeftPtr <= mid && RightPtr <= high){
		if (A[LeftPtr] < A[RightPtr])
			B[BufPtr++] = A[LeftPtr++];
		else B[BufPtr++] = A[RightPtr++];
	}
	if (LeftPtr > mid)
		for (int i = RightPtr; i <= high; i++) 
			B[BufPtr++] = A[i];
	else 
		for (int i = LeftPtr; i <= mid; i++) 
			B[BufPtr++] = A[i];

	// 합병이 끝나면 함수가 끝나기 때문에 넣어줘야한다.
	for (int i = low; i <= high; i++) 
		A[i] = B[i];
}

void MergeSort(int A[], int low, int high){
	int mid;
	if (low < high){
		mid = (low + high) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid+1, high);
		Merge(A, low, mid, high);
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

	MergeSort(a, 0, N);

	printf("[ ");
	for (int i = 0; i <= N; i++){
		printf("%2.d ", a[i]);
	} printf(" ] / [END]\n");

}