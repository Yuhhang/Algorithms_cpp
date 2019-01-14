#include <iostream>
//#include <algorithm>
using namespace std;

void qsort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main()
{
	int a[10] = { 45,894,5668,21,64,95,37,2,50,4 };

	//cout << a << endl << endl;

	qsort(a, 0, 9);

	for (int i = 0; i < 10; i++) { cout << a[i] << " "; }
	//cout << a;
	system("pause");
}

void qsort(int a[], int low, int high)
{
	if (high <= low)  return;
	int j = partition(a, low, high);
	qsort(a, low, j - 1);
	qsort(a, j + 1, high);
}

int partition(int a[], int low, int high)
{
	int i = low; int j = high + 1;
	int pivot = a[low];
	while (true)
	{
		while (a[++i] < pivot)
			if (i == high)
				break;
		while (a[--j] > pivot)
			if (j == low)	
				break;
		if (i >= j)		
			break;
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	int temp1 = a[low];
	a[low] = a[j];
	a[j] = temp1;
	return j;
}