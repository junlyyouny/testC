#define MAX 100
#include <stdio.h>

typedef int DataType;

// i,j,v分别为非0元素所在的行、列和其值
typedef struct
{
	int i, j;
	DataType v;
}Element;

// 第0行放置矩阵的行、列数和非0个数
typedef struct
{
	int m, n, t;
	Element data[MAX+1];
}SpMatrix;

void TransMat(SpMatrix M, SpMatrix *N)
{
	int b, col, k;
	N->m = M.n;
	N->n = M.m;
	N->t = M.t;
	if(N->t > 0) {
		b = 1;
		for(col = 1; col <= M.n; col++) 
		{
			for(k = 1; k <= M.t; k++)
			{
				if(M.data[k].j == col) {
					N->data[b].i = M.data[k].j;
					N->data[b].j = M.data[k].i;
					N->data[b].v = M.data[k].v;
					b++;
				}
			}
		}
	}
}

void main()
{
	int s;
	SpMatrix a = {
		5,5,7,
		{
			{0,0,0},
			{1,3,5},
			{1,5,-6},
			{2,3,12},
			{2,5,15},
			{3,1,2},
			{3,3,7},
			{5,2,11}
		}
	};
	SpMatrix *p = &a;
	printf("输出转置前的矩阵三元表：\n");
	for(s = 1; s <= a.t; s++) {
		printf("%5d%5d%5d\n", a.data[s].i, a.data[s].j, a.data[s].v);
	}
	printf("\n\n");
	TransMat(a, p);
	printf("输出转置后的矩阵三元表：\n");
	for(s=1;s<=a.t;s++) {
		printf("%5d%5d%5d\n", a.data[s].i, a.data[s].j, a.data[s].v);
	}
	printf("\n\n");
}
