#include <stdio.h>
#include <stdlib.h>
#define VEXN 5
#define EDGEN 7
#define VexType char
#define EdgeType int

typedef struct EdgeNode
{
    int Adjvex;
    EdgeType Arc;
    struct EdgeNode *NextArc;
}ArcNode;

typedef struct
{
    VexType vex;
    ArcNode *FirstArc;
}VexNode;

typedef struct
{
    VexNode AdjList[VEXN+1];
    int VexNum, ArcNum;
}AdjGraph;

int Visited[VEXN+1];
AdjGraph *G;
int AL[EDGEN+1][3] = {
        {0,0,0},{1,2,4},{1,3,5},{2,3,8},
        {2,4,3},{3,4,7},{3,5,2},{4,5,6}
    };

//建立并输出邻接表和分别按各个顶点为起点遍历
void Creat_AdjGraph( )
{
    int i, j, k;
    EdgeType v;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    G->VexNum = VEXN;
    G->ArcNum = EDGEN;
    printf("VexNum=%d\nArcNumber=%d\n", G->VexNum, G->ArcNum);
    for(i=1; i <= G->VexNum; i++)
    {
        G->AdjList[i].vex = 64+i;
        G->AdjList[i].FirstArc = NULL;
    }
    printf("\n");
    for(k = 1; k <= G->ArcNum; k++)
    {
        i = AL[k][0];
        j = AL[k][1];
        v = AL[k][2];
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->Adjvex = j;
        p->Arc = v;
        p->NextArc = G->AdjList[i].FirstArc;
        G->AdjList[i].FirstArc = p;
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->Adjvex = i;
        p->Arc = v;
        p->NextArc = G->AdjList[j].FirstArc;
        G->AdjList[j].FirstArc = p;
    }
    printf("Adjacency list:\n\n");
    for(k = 1; k <= G->VexNum; k++)
    {
        printf("%5d%3c  ->", k, G->AdjList[k].vex);
        p = G->AdjList[k].FirstArc;
        while(p != NULL)
        {
            printf("%5d%3d", p->Adjvex, p->Arc);
            p = p->NextArc;
        }
        printf("\n");
    }
    printf("\n");
}

//递归遍历网
void DFS_Adj(int v0)
{
    ArcNode *p;
    printf("%5c", G->AdjList[v0].vex);
    Visited[v0] = 1;
    p = G->AdjList[v0].FirstArc;
    while(p != NULL)
    {
        if(Visited[p->Adjvex] == 0) {
            DFS_Adj(p->Adjvex);
        }
        p = p->NextArc;
    }
}

void main()
{
    int i, j;
    Creat_AdjGraph();
    printf("Depth-First Search:\n\n");
    for(i = 1; i <= G->VexNum; i++)
    {
        for(j=1; j <= VEXN; j++) {
            Visited[j] = 0;
        }
        printf("From %c start:", G->AdjList[i].vex);
        DFS_Adj(i);
        printf("\n");
    }
}
