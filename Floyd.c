#include <stdio.h>
#include <stdlib.h>
#define VEXN 4
#define MAX 9999

int a[VEXN+1][VEXN+1], path[VEXN+1][VEXN+1];
int arcs[VEXN+1][VEXN+1] = {
        {0,  0,  0,  0,  0},
        {0,  0,  1,MAX,  4},
        {0,MAX,  0,  9,  2},
        {0,  3,  5,  0,  8},
        {0,MAX,MAX,  6,  0}
    };

void print_matrix(int m[VEXN+1][VEXN+1])
{
    int i, j;
    for(i = 1; i <= VEXN; i++) {
        printf("\tv%d", i);
    }
    printf("\n\n");
    for(i = 1; i <= VEXN; i++)
    {
        printf("v%d\t", i);
        for(j = 1; j <= VEXN; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void floyd()
{
    int i, j, k, next;
    for(i = 1; i <= VEXN; i++) {
        for(j = 1; j <= VEXN; j++)
        {
            a[i][j] = arcs[i][j];
            path[i][j] = (i != j && a[i][j] < MAX) ? i : 0;
        }
    }
    printf("Arcs[0]:\n");
    print_matrix(a);
    printf("Path[0]:\n");
    print_matrix(path);
    printf("--------------------------------------------\n");
    getchar();
    for(k=1;k<=VEXN;k++)
    {
        for(i = 1; i <= VEXN; i++) {
            for(j = 1; j <= VEXN; j++) {
                if(a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    path[i][j] = path[k][j];
                }
            }
            printf("Arcs[%d]:\n", k);
            print_matrix(a);
            printf("Path[%d]:\n", k);
            print_matrix(path);
            printf("--------------------------------------------\n");
            getchar();
        }
    }
    printf("\nPATH:\n");
    for(i = 1; i <= VEXN; i++) {
        for(j = 1; j <= VEXN; j++)
        {
            if(i != j)
            {
                printf("v%d -> v%d%5d : ", i, j, a[i][j]);
                next = path[i][j];
                printf("v%d", j);
                    while(next != i)
                    {
                        printf(" <- v%d", next);
                        next = path[i][next];
                    }
                printf(" <- v%d\n", i);
            }
        }
    }
}

void main()
{
    floyd();
    getchar();
}
