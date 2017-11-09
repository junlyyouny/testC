#include <stdio.h>
#define VEX 6
#define EDGE 10

struct edgeset
{
	int fromvex;
	int endvex;
	int weight;
};

struct edgeset c[VEX], ge[EDGE+1] = {
		{0,0,0},{1,3,1},{4,6,2},{2,5,3},{3,6,4},{1,4,5},
		{3,5,5},{2,3,5},{1,2,6},{5,6,6},{3,4,7}
	};

void kruskal(struct edgeset ge[EDGE+1])
{
	int i, j, m1, m2, k = 1, d = 1;
	int s[VEX+1][VEX+1];
	for(i = 1; i <= VEX; i++) {
		for(j = 1; j <= VEX; j++) {
			s[i][j] = (i == j) ? 1 : 0;
		}
	}
	while(k < VEX)
	{
		for(i = 1; i <= VEX; i++) {
			for(j = 1; j <= VEX; j++)
			{
				if(ge[d].fromvex == j && s[i][j] == 1) {
					m1 = i;
				}
				if(ge[d].endvex == j && s[i][j] == 1) {
					m2 = i;
				}
			}
		}
		if(m1 != m2)
		{
			c[k] = ge[d];
			k++;
			for(j = 1; j <= VEX; j++)
			{
				s[m1][j] = s[m1][j] || s[m2][j];
				s[m2][j] = 0;
			}
		}
		d++;
	}
}

void main()
{
	int i, min = 0;
	printf("克鲁斯卡尔前\n始顶点-终顶点:权值\n");
	for(i = 1; i <= EDGE; i++) {
		printf("(%d,%d)=%d\n", ge[i].fromvex, ge[i].endvex, ge[i].weight);
	}
	printf("\n");
	kruskal(ge);
	printf("克鲁斯卡尔后\n始顶点-终顶点:权值\n");
	for(i = 1; i < VEX; i++)
	{
		printf("(%d,%d)=%d\n", c[i].fromvex, c[i].endvex, c[i].weight);
		min += c[i].weight;
	}
	printf("\n最小权值之和=%d\n", min);
}
