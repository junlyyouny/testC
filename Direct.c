#include <stdio.h>
#define N 5

typedef int DataType;

void SelectSort(int n, DataType R[])
{
	int i, j, m, c;
	DataType t;
	for(i = 0; i < n-1; i++)
	{
		m = i;
		for(j = i+1; j < n; j++) {
			if(R[j] < R[m]) {
				m = j;
			}
		}
		if(m != i) {
			t = R[i];
			R[i] = R[m];
			R[m] = t;
		}
		printf("\nCircle %d:", i+1);
		for(c = 0; c < n; c++) {
			printf("%5d", R[c]);
		}
		printf("\n");
		getchar();
	}
}

void main()
{
	DataType i, a[N] = {5, 3, 1, 4, 2};
	printf("\nSelect Sort\n\nCircle 0:");
	for(i = 0; i < N; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");
	SelectSort(N, a);
	printf("\n");
}
