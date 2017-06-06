#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}*LinkList;

void visit(LinkList L)
{
    LinkList p = L->next;
    while(p != NULL){
        printf("%5d", p->data);
        p = p->next;
    }
    printf("\n\n");
}

LinkList creat()
{
    int n = 0; LinkList f1,f2,f3,k;
    f1 = (LinkList)malloc(sizeof(struct node));
    f2 = (LinkList)malloc(sizeof(struct node));
    f1->data = f2->data = 1;
    k = f1;
    f1->next = f2;
    for(n=3;n<=10;n++)
    {
        f3 = (LinkList)malloc(sizeof(struct node));
        f3->data = f1->data + f2->data;
        f2->next = f3;
        f1 = f2;
        f2 = f3;
    }
    f3->next = NULL;
    return k;
}

void fun(LinkList h)
{ 
    int m; LinkList p,q,s;
    p = h->next;
    q = h;
    m = p->data;
    s = q;
    while(p != NULL){
        if(p->data >m){
           m = p->data;
           s = q;
        }
        q = p;
        p = p->next;
    }
    p = s->next;
    s->next = p->next;
    free(p);
 }

int main(void) 
{
    LinkList L;
    L = creat();
    visit(L);
    fun(L);
    visit(L);
    return 0;
}
