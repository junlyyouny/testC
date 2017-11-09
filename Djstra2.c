#include <stdio.h>
#define VI  0
#define MAX 9999
#define VEXN 5

int dist[VEXN];
int path[VEXN];
int s[VEXN];
int arcs[][VEXN] = {
        {MAX, 10,MAX, 30, 90},
        {MAX,MAX, 50,MAX,MAX},
        {MAX,MAX,MAX,MAX, 10},
        {MAX,MAX, 20,MAX, 60},
        {MAX,MAX,MAX,MAX,MAX}
    };

void shortest_path(int n)
{
    int i, j, w, pre, min, u, t, temp[VEXN];
    for(i = 0; i < n; i++)
    {
        dist[i] = arcs[VI][i];
        s[i] = 0;
        if(i != VI && dist[i] < MAX) {
            path[i] = VI;
        } else {
            path[i] = 0;
        }
    }
    s[VI] = 1;
    dist[VI] = 0;
    for(i = 0; i < n; i++)
    {
        min = MAX;
        u = VI;
        for(j = 0; j < n; j++) {
            if(!s[j]&&dist[j] < min) {
                u = j, min = dist[j];
            }
        }
        s[u] = 1;
        for(w = 0; w < n; w++) {
            if(!s[w]&&arcs[u][w] < MAX && dist[u] + arcs[u][w] < dist[w])
            {
                dist[w] = dist[u] + arcs[u][w];
                path[w] = u;
            }
        }
    }
    for(i = 0; i < n; i++)
    if(i != VI)
    {
        printf("%5d:%5d<-", dist[i], i+1);
        pre = path[i];
        while(pre != 0) {
            printf("%d<-", pre+1);
            pre = path[pre];
        }
        printf("%d\n", VI+1);
    }
}

main()
{
    int i, j;
    printf("AdjMatrix:\n\n ");
    for(i = 0; i < VEXN; i++) {
        printf("%8d", i+1);
    }
    printf("\n\n");
    for(i = 0; i < VEXN; i++)
    {
        printf("%d", i+1);
        for(j = 0; j < VEXN; j++)
            printf("%8d", arcs[i][j]);
        printf("\n");
    }
    printf("\nShortest Path:\n\n");
    shortest_path(VEXN);
}
