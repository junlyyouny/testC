#include <stdio.h>
#define N 8

typedef int DataType;

void CreatHeap(int i, int n, DataType R[])
{
	int j = 2*i;
	DataType t = R[i];
	while(j < n)
	{
		if(j < n && R[j] < R[j+1]) {
			j++;
		}
		if(R[j] > t) {
			R[i] = R[j];
			i = j;
			j = 2*i;
		} else {
			j = n;
		}
		R[i] = t;
	}
}

void HeapSort(int n, DataType R[])
{
	int i;
	DataType t;
	for(i = n/2; i >= 0; i--) {
		CreatHeap(i, n, R);
	}
	for(i = n-1; i >= 0; i--)
	{
		t = R[0];
		R[0] = R[i];
		R[i] = t;
		CreatHeap(0, i-1, R);
	}
}

void main( )
{
	int i;
	DataType a[N] = {16,20,17,13,28,14,23,15};
	printf("\nHeap Sort\n\nSouce: ");
	for(i = 0; i < N; i++) {
		printf("%5d", a[i]);
	}
	HeapSort(N, a);
	printf("\n\n Sort: ");
	for(i = 0; i < N; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");
}
