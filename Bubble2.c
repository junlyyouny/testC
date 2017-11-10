#include <stdio.h>
#define N 5

typedef int Datatype;

void BubbleSort(int n, Datatype R[])
{
	int i, j, k, flag = 1;
	Datatype t;
	for(i = 1; i < n; i++)
	{
		flag = 0;
		printf("\nCircle %d:", i);
		for(j = n-1; j >= i; j--) {
			if(R[j] < R[j-1]) {
				t = R[j], R[j] = R[j-1], R[j-1] = t, flag = 1;
			}
		}
		for(k = 0; k < n; k++) {
			printf("%5d", R[k]);
		}
		printf("\n");
		getchar();
		if(flag == 0) {
			return;
		}
	}
}

void main()
{
	int i;
	Datatype a[N] = {5,3,4,1,2};
	printf("Bubble Sort\n\nCircle 0:");
	for(i = 0; i < N; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");
	getchar();
	BubbleSort(N, a);
	printf("\n");
}
