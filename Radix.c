#include <stdio.h>
//排序个数
#define N 10 
//位数
#define D 3

void main()
{
	int i, j, k, r, t, p = 1;
	int a[N] = {123,78,65,9,108,7,8,3,68,309};
	int F[10][N] = {0};
	int E[10] = {0};
	printf("\n  Source: ");
	for(i = 0; i < N; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");
	getchar();
	for(r = 1; r <= D; r++)
	{
		printf("\n Time %d:\n",r);
		//分配
		for(i = 0; i < N; i++)
		{
			k = a[i] / p % 10;
			F[k][E[k]] = a[i];
			E[k]++;
		}
		p *= 10;
		//收集
		for(i = 0; i < 10; i++)
		{
			printf("\n  F%d -> ", i);
			for(j = 0; j < E[i]; j++) {
				printf(" %-d->", F[i][j]);
			}
			printf(" E%d\n", i);
		}
		t = 0;
		for(i = 0; i < 10; i++) {
			for(j = 0; j < E[i]; j++) {
				a[t++] = F[i][j];
			}
		}
		printf("\n Sort%d:", r);
		for(i = 0; i < N; i++) {
			printf("%5d", a[i]);
		}
		printf("\n");
		for(i = 0; i < 10; i++)
		{
			E[i] = 0;
			for(j = 0; j < N; j++) {
				F[i][j] = 0;
			}
		}
		getchar();
	}
}
