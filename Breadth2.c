#include <stdio.h>
#define VEXN 5
#define MAX 9999

int arcs[VEXN][VEXN] = {
        {MAX,4,5,MAX,MAX},
        {4,MAX,8,3,MAX},
        {5,8,MAX,7,2},
        {MAX,3,7,MAX,6},
        {MAX,MAX,2,6,MAX}
    };
int visited[VEXN];

void BFS(int i)
{
    int q[VEXN];
    int j, f = 0, r = 0;
    printf("%3c", 65+i);
    visited[i] = 1;
    q[++r] = i;
    while(f < r)
    {
        i = q[++f];
        for(j = 0; j < VEXN; j++) {
            if(arcs[i][j] < MAX && visited[j] == 0)
            {
                printf("%3c", 65+j);
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
        printf("%-c\t", 65+i);
    }
    printf("\n\n");
    for(i = 0; i < VEXN; i++)
    {
        printf("%c\t", 65+i);
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
        printf("From %c start:", 65+v);
        BFS(v);
        printf("\n");
    }
}
