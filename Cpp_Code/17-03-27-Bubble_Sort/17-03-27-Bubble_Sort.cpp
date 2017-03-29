#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void Bubble_Sort(int a[], int max){
	for (int i = max; i > 1; i--){
		for (int j = 0; j < i; j++){
			if (a[j] >= a[j + 1]){
				Swap(a[j], a[j + 1]);
				printf("[ ");
				for (int k = 0; k <= max; k++){
					printf("%2.d ", a[k]);
				} printf(" ] / [Swap >> %2.d <=> %2.d]\n", a[j], a[j+1]);
			}
		}
		printf("[CLEAR]\n");
	}
}

void main(){
	srand((unsigned)time(NULL));
	int a[10];
	int max = 9;

	printf("[ ");
	for (int i = 0; i<10; i++){
		a[i] = rand() % 100;
		printf("%2.d ", a[i]);
	} printf(" ] / [START]\n\n");

	Bubble_Sort(a, max);

	printf("[ ");
	for (int i = 0; i <= max; i++){
		printf("%2.d ", a[i]);
	} printf(" ] / [END]\n");

}