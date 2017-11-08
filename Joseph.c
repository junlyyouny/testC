#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *Creat(int n);

void Joseph(Node *rear, int m);

void main()
{
    int m, n;
    Node *rear = NULL;
    printf("输入约瑟夫环的长度: ");
    scanf("%d", &n);
    printf("输入密码: ");
    scanf("%d", &m);
    rear = Creat(n);
    Joseph(rear,m);
}

Node *Creat(int n)
{
    int i;
    Node *rear = NULL, *s;
    rear = (Node *)malloc(sizeof(Node));
    rear->data = 1;
    rear->next = rear;
    for(i=2; i<=n; i++)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = i;
        s->next = rear->next;
        rear->next = s;
        rear = s;
    }
    return rear;
}

void Joseph(Node *rear, int m)
{
    Node *pre = rear, *p = rear->next, *q;
    int count = 1;
    printf("出环的顺序是:\n");
    while(p->next != p)
    if(count < m) {
        pre = p;
        p = p->next;
        count++;
    } else {
        printf("%4d", p->data);
        q = p;
        pre->next = p->next;
        p = pre->next;
        free(q);
        count = 1;
  }
    printf("%4d\n", p->data);
    free(p);
}
