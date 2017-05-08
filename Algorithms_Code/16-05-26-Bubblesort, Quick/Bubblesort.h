#ifndef __MYSORT_H_
#define __MYSORT_H_
class Bubblesort{
private:
	void Swap(int & ref1, int &ref2);
	int Partition(int arr[], int left, int right);
public:
	void BubbleSort(int arr[], int len);
	void QuickSort(int arr[], int left, int right);
};

#endif