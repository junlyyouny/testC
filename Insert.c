#include <stdio.h>
#define N 8

typedef int DataType;

void StraightInsertSort(int n, DataType R[])
{
	int i, j, c;
	DataType t;
	for(i = 1; i < n; i++)
	{
		t = R[i];
		for(j = i-1; j >= 0; j--) {
			if(R[j] > t) {
				R[j+1] = R[j];
			} else {
				break;
			}
		}
		R[j+1] = t;
		printf("\nCircle %d:", i);
		for(c = 0; c < n; c++) {
			printf("%5d", R[c]);
		}
		printf("\n");
		getchar();
	}
}

void main()
{
	int i;
	DataType a[N] = {22,20,17,13,28,14,22,15};
	printf("Stright Insert Sort\n\nCircle 0:");
	for(i = 0; i < N; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");
	StraightInsertSort(N, a);
	printf("\n");
}
