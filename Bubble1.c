#include <stdio.h>
#define N 5

typedef int Datatype;

void BubbleSort(int n, Datatype R[])
{
	int i, j, c;
	Datatype t;
	//趟数
	for(i = 0; i < n-1; i++)
	{
		printf("\nCircle %d:", i+1);
		for(j = 0; j < n-1-i; j++) {
			//交换
			if(R[j] > R[j+1]) {
				t = R[j], R[j] = R[j+1], R[j+1] = t; 
			}
		}
		for(c = 0; c < n; c++) {
			printf("%5d", R[c]);
		}
		printf("\n");
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
	BubbleSort(N, a);
	printf("\n");
}
