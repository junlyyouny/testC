#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct node
{
    DataType data;
    struct node *next;
}LinkList;

typedef struct
{
    LinkList *rear;
}LinkQueue;

//置空队
LinkQueue *InitQueue()
{
    LinkQueue *q;
    // 申请链队的尾指针结点
    q = (LinkQueue *)malloc(sizeof(LinkQueue));
    // 申请头结点
    q->rear = (LinkList *)malloc(sizeof(LinkList));
    // 头结点的尾指针指向自身
    q->rear->next = q->rear;
    return q;
}

//判空队
int IsEmpty(LinkQueue *q)
{
   return q->rear == q->rear->next;
}

//入队
void EnQueue(LinkQueue *q, DataType value)
{
    LinkList *s;
    // 申请新结点
    s = (LinkList *)malloc(sizeof(LinkList));
    s->data = value;
    s->next = q->rear->next;
    q->rear->next = s;
    q->rear = s;
}

//出队
void DeQueue(LinkQueue *q)
{
    DataType x;
    if(IsEmpty(q)) {
        printf("队是空的！\n");
        return;
    }
    x = q->rear->next->next->data;
    q->rear->next->next = q->rear->next->next->next;
    printf("出队的元素是:%c\n", x);
}

//遍历队列（单链表）
void VisitQueue(LinkQueue *q)
{
    LinkList *s = q->rear->next->next;
    while(s != NULL && s != q->rear->next)
    {
        printf("%2c", s->data);
        s = s->next;
    }
}

main()
{
    DataType da;
    LinkQueue *p;
    //置空队
    p = InitQueue();
    if(IsEmpty(p)) {
        printf("\n\n经测试队是空的！\n\n");
    } else {
        printf("经测试队是非空的！\n\n");
    }
    printf("输入将要首次入队的元素字符串（换行作为结束）：");
    scanf("%c", &da);
    while(da != '\n')
    {
        EnQueue(p, da);
        scanf("%c", &da);
    }
    printf("首次生成的队列是：");
    VisitQueue(p);
    printf("\n\n");
    printf("输入一个要入队的元素：");
    scanf("%c", &da);
    EnQueue(p, da);
    printf("入队后的新队列是：");
    VisitQueue(p);
    printf("\n\n");
    DeQueue(p);
    printf("出队后的新队列是：");
    VisitQueue(p);
    printf("\n\n");
}