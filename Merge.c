#include <stdio.h>
#define N 8

typedef int DataType;

void Merge(DataType R[], DataType A[], int low, int mid, int high)
{
	int i = low, j = mid+1, k = low;
	while(i <= mid && j <= high) {
		if(R[i] < R[j]) {
			A[k++] = R[i++];
		} else {
			A[k++] = R[j++];
		}
	}
	while(i <= mid) {
		A[k++] = R[i++];
	}
	while(j <= high) {
		A[k++] = R[j++];
	}
}

void MergePass(DataType R[], DataType A[], int n, int len)
{
	int i = 0, j;
	while(i+2*len-1 <= n)
	{
		Merge(R, A, i, i+len-1, i+2*len-1);
		i += 2*len;
	}
	if(i+len-1 < n) {
		Merge(R, A, i, i+len-1, n-1);
	} else { 
		for(j = i; j <= n-1; j++) {
			A[j] = R[j];
		}
	}
}

void MergeSort(DataType R[], int n)
{
	int len = 1;
	DataType A[N];
	while(len < n)
	{
		MergePass(R, A, n, len);
		len *= 2;
		MergePass(A, R, n, len);
		len *= 2;
	}
}

void main()
{
	int i;
	DataType a[N] = {22,20,17,13,28,14,23,15};
	printf("\nMerge Sort\n\nSouce: ");
	for(i = 0; i < N; i++) {
		printf("%5d", a[i]);
	}
	MergeSort(a, N);
	printf("\n\n Sort: ");
	for(i = 0; i < N; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");
}
