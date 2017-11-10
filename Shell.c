#include <stdio.h>
#define N 8

typedef int DataType;

void ShellSort(DataType a[], int n)
{
	int i, j, gap;
	DataType temp;
	for(gap = n/2; gap >= 1; gap /= 2)
	{
		printf(" gap=%d:", gap);
		for(i = gap; i < n; i++)
		{
			temp = a[i];
			for(j = i-gap; j >= 0; j -= gap) {
				if(a[j] > temp) {
					a[j+gap] = a[j];
				} else {
					break;
				}
			}
			a[j+gap] = temp;
		}
		for(i = 0; i < n; i++) {
			printf("%5d", a[i]);
		}
		printf("\n");
		getchar();
	}
}

void main()
{
	int i;
	DataType R[N] = {17,3,30,25,14,18,20,9};
	printf("\nSource:");
	for(i = 0; i < N; i++) {
		printf("%5d", R[i]);
	}
	printf("\n");
	ShellSort(R, N);
	printf("  Sort:");
	for(i = 0; i < N; i++) {
		printf("%5d", R[i]);
	}
	printf("\n");
}
