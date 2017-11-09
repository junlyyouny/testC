#define LEAFN 4
#define M 2 * LEAFN - 1
#define MIN 9999
#include <stdio.h>

struct tree
{
    int weight, parent, lch, rch;
}hftree[M+1] = {{0},{4},{5},{6},{7}};

void creathuffmantree()
{
    int i, j, p1, p2, s1, s2;
    for(i = LEAFN + 1; i <= M; i++)
    {
        p1 = p2 = 0;
        s1 = s2 = MIN;
        for(j = 1; j <= i-1; j++) {
            if(hftree[j].parent == 0) {
                if(hftree[j].weight < s1) {
                    s2 = s1;
                    s1 = hftree[j].weight;
                    p2 = p1;
                    p1 = j;
                } else if(hftree[j].weight < s2) {
                    s2 = hftree[j].weight;
                    p2 = j;
                }
            }
        }
        hftree[p1].parent = hftree[p2].parent = i;
        hftree[i].lch = p1;
        hftree[i].rch = p2;
        hftree[i].weight = hftree[p1].weight + hftree[p2].weight;
    }
}

void main()
{
    int i;
    printf("\nBefore Huffman\n Order Weight Parent Lchild Rchild:\n");
    for(i = 1; i <= M; i++) {
        printf("%4d%7d%7d%7d%7d\n", 
            i, 
            hftree[i].weight,hftree[i].parent, 
            hftree[i].lch, 
            hftree[i].rch
        );
    }
    creathuffmantree();
    printf("\nAfter Huffman\n Order Weight Parent Lchild Rchild:\n");
    for(i = 1; i <= M; i++) {
        printf("%4d%7d%7d%7d%7d\n",
            i,
            hftree[i].weight,
            hftree[i].parent,
            hftree[i].lch,
            hftree[i].rch
        );
    }
}
