#define VEXN 5
#define EDGEN 7
#define MAX 9999
#include<stdio.h>

char Vexs[VEXN];
int Visited[VEXN];
int Arcs[VEXN][VEXN] = {
		{MAX, 4, 5, MAX, MAX},
		{4, MAX, 8, 3, MAX},
		{5, 8, MAX, 7, 2},
		{MAX, 3, 7, MAX, 6},
		{MAX, MAX, 2, 6, MAX}
	};

//输出邻接矩阵和分别按各个顶点为起点遍历
void Creat_MGraphN()
{
	int i, j, k;
	printf("VexNum=%d\nArcNum=%d\n", VEXN, EDGEN);
	printf("\nAdjMatrix:\n\n ");
	for(i = 0; i < VEXN; i++)
	{
		Vexs[i] = 65+i;
		printf("%8c", Vexs[i]);
	}
	printf("\n\n");
	for(i = 0; i < VEXN; i++)
	{
 		printf("%c", 65+i);
		for(j = 0; j < VEXN; j++) {
			printf("%8d", Arcs[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//递归遍历网
void DFS(int v0)
{
	int j;
	printf("%5c", Vexs[v0]);
	Visited[v0] = 1;
	for(j = 0; j < VEXN; j++) {
		if(Arcs[v0][j] != MAX && Visited[j] == 0) {
			DFS(j);
		}
	}
}

void main()
{
	int i, j;
	Creat_MGraphN();
	printf("Depth-First Search:\n\n");
	for(i = 0; i < VEXN; i++)
	{
		for(j = 0; j < VEXN; j++) {
			Visited[j] = 0;
		}
		printf("From %c start:", Vexs[i]);
		DFS(i);
		printf("\n");
	}
	printf("\n");
}
