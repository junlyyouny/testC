#include <stdio.h>
#define VEX 7
#define MV 9999

struct edgeset
{
    int fromvex;
    int endvex;
    int weight;
};

struct edgeset ct[VEX+1];

int s[VEX+1][VEX+1] = {
        {0,0,0,0,0,0,0,0},
        {0, 0, 8, 5,MV,MV,MV,MV},
        {0, 8, 0, 3,12,MV,10,MV},
        {0, 5, 3, 0,MV,15,MV, 7},
        {0,MV,12,MV, 0,MV, 6, 2},
        {0,MV,MV,15,MV, 0,MV,MV},
        {0,MV,10,MV, 6,MV, 0, 9},
        {0,MV,MV, 7, 2,MV, 9, 0}
    };

void prim(struct edgeset ct[VEX+1])
{
    int i, j, k, m, t, w, min;
    struct edgeset temp;
    for(i = 1; i < VEX; i++)
    {
        ct[i].fromvex = 1;
        ct[i].endvex = i+1;
        ct[i].weight = s[1][i+1];
    }
    for(k = 2; k <= VEX; k++)
    {
        min = MV;
        m = k-1;
        for(j = k-1; j < VEX; j++) {
            if(ct[j].weight < min) {
                min = ct[j].weight;
                m = j;
            }
        }
        temp = ct[k-1];
        ct[k-1] = ct[m];
        ct[m] = temp;
        j = ct[k-1].endvex;
        for(i = k; i < VEX; i++)
        {
            t = ct[i].endvex;
            w = s[j][t];
            if(w < ct[i].weight) {
                ct[i].weight = w;
                ct[i].fromvex = j;
            }
        }
    }
}

void main()
{
    int i, j, min = 0;
    printf("邻接矩阵:\n ");
    for(i = 1; i <= VEX; i++) {
        printf("%8c", 64+i);
    }
    printf("\n\n");
    for(i = 1; i <= VEX; i++)
    {
        printf("%c", 64+i);
        for(j = 1; j <= VEX; j++) {
            printf("%8d", s[i][j]);
        }
        printf("\n");
    }
    printf("\n普里姆:\n\n");
    prim(ct);
    for(i = 1; i < VEX; i++)
    {
        printf("(%c,%c)=%d\n", 64+ct[i].fromvex, 64+ct[i].endvex, ct[i].weight);
        min += ct[i].weight;
    }
    printf("\n最小权值之和=%d\n", min);
}
