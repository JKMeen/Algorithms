#include <stdio.h>

typedef struct person {
	char name[10];
	int age;
	float pay;
	struct {
		int year;
		int month;
		int day;
	};
} company;

void main(){
	int n;
	int maxage, max=0, num=0;
	printf("사람 수 입력 >> ");
	scanf("%d", &n);
	company p[50];

	for (int i = 0; i < n; i++){
		printf("%i 번째 이름, 나이, 월급, 년, 월, 일을 순서대로 입력 >> \n", i+1);
		scanf("%s %d %f %d %d %d", &p[i].name, &p[i].age, &p[i].pay, &p[i].year, &p[i].month, &p[i].day);
		num += p[i].age;
	}
	maxage = p[0].age;

	for (int i = 0; i < n; i++){
		if (maxage <= p[i].age){
			maxage = p[i].age;
			max = i;
			printf("maxage : %d, p[i].age : %d \n", maxage, p[i].age);
		}
	}
	printf("나이가 제일 많은 사람 >> %s %d세 %.1f원 %d년 %d월 %d일 >> \n", p[max].name, p[max].age, p[max].pay, p[max].year, p[max].month, p[max].day);
	printf("나이 평균 >> %d 세 \n", num / n);
}