#include <stdio.h>
#define VEXN 7

int arcs[VEXN][VEXN] = {
        {0,1,1,1,0,0,0},
        {0,0,0,0,1,1,1},
        {0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };
int visited[VEXN];

//广度优先遍历
void BFS(int i)
{
    //队列
    int q[VEXN];
    int j, f = 0, r = 0;
    printf("v%-5d", i);
    visited[i] = 1;
    q[++r] = i;
    while(f < r)
    {
        i = q[++f];
        for(j = 0; j < VEXN; j++) {
            if(arcs[i][j] == 1 && visited[j] == 0)
            {
                printf("v%-5d", j);
                visited[j] = 1;
                q[++r] = j;
            }
        }
    }
}

void main()
{
    int i, j, v;
    printf("\nAdjMatrix:\n\n\t");
    for(i = 0; i < VEXN; i++) {
        printf("v%-d\t", i);
    }
    printf("\n\n");
    for(i = 0; i < VEXN; i++)
    {
        printf("v%-8d", i);
        for(j = 0; j < VEXN; j++) {
            printf("%d\t", arcs[i][j]);
        }
        printf("\n");
    }
    printf("\nBeadth-First Search:\n\n");
    for(v = 0; v < VEXN; v++)
    {
        for(i = 0; i < VEXN; i++) {
            visited[i] = 0;
        }
        printf("From v%d start: ", v);
        BFS(v);
        printf("\n");
    }
}
