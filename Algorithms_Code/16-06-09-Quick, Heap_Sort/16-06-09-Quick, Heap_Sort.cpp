#include <iostream>
using namespace std;

void swap(int&a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int partition(int*data, int left, int right)
{
	int i, j, pivot;
	i = left - 1;
	pivot = data[right];
	for (j = left; j < right; j++) {
		if (data[j] < pivot) {
			swap(data[++i], data[j]);
		}
	}
	swap(data[++i], data[right]);
	return i;
}

void quicksort(int*data, int left, int right)
{
	if (right > left)
	{
		int middle = partition(data, left, right);
		quicksort(data, left, middle - 1);
		quicksort(data, middle + 1, right);
	}
}

void heapify(int data[], int index, int n)
{
	int left, right;
	left = 2 * index;
	right = 2 * index + 1;

	if (left > n) return;

	else if (right > n)
	{
		if (data[left] > data[index])
			swap(data[left], data[index]);
	}

	else
	{
		int large;
		if (data[left] > data[right])
			large = left;
		else
			large = right;

		if (data[large] > data[index])
		{
			swap(data[large], data[index]);
			heapify(data, large, n); // ����Լ� ȣ�� ������ �Ǵ� �ڽ� large�� �ּҷ� ȣ��.
		}
	}
}

void buildHeap(int data[], int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		heapify(data, i, n);
	}
}

void heapSort(int data[], int n)
{
	buildHeap(data, n);
	for (int i = n;i > 1; i--)
	{
		swap(data[1], data[i]);
		heapify(data,1,i-1); // ���� �ڽ��� ���ڰ� �پ�� �ϹǷ� i�� ���� 1�� ����.
	}
}

int main()
{
	//�������Է�
	int n;
	int* data;

	cout << "�������� ���� �Է�:";
	cin >> n;
	data = new int[n+1];
	for (int i = 1; i < n+1; i++) cin >> data[i];
	//quicksort(data, 0, n - 1);
	heapSort(data, n);

	//���ĵ� ������ ���
	for (int i = 1; i < n+1; i++)
		cout << data[i] << " ";
	delete[] data;
	return 0;
}