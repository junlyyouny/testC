#include <stdio.h>
#define N 5

typedef int DataType;

void SelectSort(int n, DataType R[])
{
	int i, j, c;
	DataType t;
	for(i = 0; i < n-1; i++)
	{
		for(j = i+1; j < N; j++) {
			if(R[i] > R[j]) {
				t = R[i];
				R[i] = R[j];
				R[j] = t;
			}
		}
		printf("\nCircle %d:", i+1);
		for(c = 0; c < n; c++) {
			printf("%5d", R[c]);
		}
		printf("\n");
	}
}

void main()
{
	DataType i, a[N] = {5,3,1,4,2};
	printf("\nSelect Sort\n\nCircle 0:");
	for(i = 0; i < N; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");
	SelectSort(N, a);
	printf("\n");
}
