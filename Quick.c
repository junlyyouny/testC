#include <stdio.h>
#define N 8

typedef int DataType;

void QuickSort(int left, int right, DataType R[])
{
	int i = left, j = right;
	DataType t = R[i];
	while(i < j)
	{
		while(i < j && R[j] > t) {
			j--;
		}
		if(i < j) {
			R[i++] = R[j];
		}
		while(i < j && R[i] <= t) {
			i++;
		}
		if(i < j) {
			R[j--] = R[i];
		}
	}
	R[i] = t;
	if(i-1 > left) {
		QuickSort(left, i-1, R);
	}
	if(i+1 < right) {
		QuickSort(i+1, right, R);
	}
}

void main()
{
	int i, begin = 0, end = N-1;
	DataType a[N] = {22,20,17,13,28,14,23,15};
	printf("Quick Sort\n\nSouce:");
	for(i = 0; i < N; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");
	QuickSort(begin, end, a);
	printf("\n Sort:");
	for(i = 0; i < N; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");
}
