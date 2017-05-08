#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void Selection_Sort(int a[], int max){
	int maxindex;
	for (int i = max; i >= 0; i--){
		maxindex = i;
		for (int j = i - 1; j >= 0; j--){
			if (a[maxindex] < a[j])
				maxindex = j;
		}
		Swap(a[i], a[maxindex]);
		printf("[ ");
		for (int k = 0; k <= max; k++){
			printf("%2.d ", a[k]);
		} printf(" ] / [Swap >> %2.d <=> %2.d]\n", a[i], a[maxindex]);
	}
}

void main(){
	srand((unsigned)time(NULL));
	int a[10];
	int max=9;

	printf("[ ");
	for (int i = 0; i<10; i++){
		a[i] = rand() % 100;
		printf("%2.d ", a[i]);
	} printf(" ] / [START]\n");
	
	Selection_Sort(a, max);

	printf("[ ");
	for (int i = 0; i <= max; i++){
		printf("%2.d ", a[i]);
	} printf(" ] / [END]\n");
	
}