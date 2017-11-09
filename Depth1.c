#define VEXN 7
#define EDGEN 8
#include <stdio.h>

int Vexs[VEXN];
int Visited[VEXN];
int Arcs[VEXN][VEXN] = {
		{0,1,1,1,0,0,0},
		{1,0,0,0,1,1,1},
		{1,0,0,0,0,0,1},
		{1,0,0,0,0,0,0},
		{0,1,0,0,0,1,0},
		{0,1,0,0,1,0,0},
		{0,1,1,0,0,0,0}
	};

//输出邻接矩阵和分别按各个顶点为起点遍历
void Creat_MGraphN()
{
	int i, j, k;
	printf("VexNum=%d\nArcNum=%d\n", VEXN, EDGEN);
	printf("\nAdjMatrix:\n\n        ");
	for(i = 0; i < VEXN; i++)
	{
		Vexs[i] = i;
		printf("V%-7d", Vexs[i]);
	}
	printf("\n\n");
	for(i = 0; i < VEXN; i++)
	{
 		printf("V%d", i);
 		for(j = 0; j < VEXN; j++) {
 			printf("%8d", Arcs[i][j]);
 		}
 		printf("\n");
	}
	printf("\n");
}

//递归深度遍历图
void DFS(int v0) 
{
	int j;
	printf("  V%d", Vexs[v0]);
	Visited[v0] = 1;
	for(j = 0; j < VEXN; j++) {
		if(Arcs[v0][j] == 1 && Visited[j] == 0) {
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
		printf("From V%d start:", Vexs[i]);
		DFS(i);
		printf("\n");
	}
	printf("\n");
}
