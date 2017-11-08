#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}LNode, *LinkedList;

//创建
LinkedList Creat()
{
	LinkedList L,r,s;
	ElemType value;
	//建立头结点
	L = (LinkedList)malloc(sizeof(LNode));
	L->next = NULL;
	//尾指针r初值指向头结点
	r = L;
	printf("生成单链表，输入int，-1作为结束：");
	scanf("%d", &value);
	while(value != -1)
	{
		//生成新结点s
		s = (LinkedList)malloc(sizeof(LNode));
		//将新结点插入表尾
		s->data = value;
		//尾指针r指向新的表尾
		r->next = s;
		r = s;
		//读入下一个结点值
		scanf("%d", &value);
	}
	//将尾结点的指针域置为空
	r->next = NULL;
	return L;
}

//遍历
void visit(LinkedList L)
{
	LinkedList p = L->next;
	while(p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n\n");
}

//前插
void InsertBefore(LinkedList L, int pos, ElemType value)
{
	//在第pos个结点前插入结点，其值为value
	LinkedList p = L->next, q = L, s;
	//指针q指向p的前驱结点
	int n = 1;
	//链表非空且未达到第pos个结点时
	while(p != NULL && n < pos)
	{
		q = p;
		//遍历下一个结点
		p = p->next;
		n++;
	}
	//找到第pos个结点
	if(p != NULL) {
		//申请新结点
		s = (LinkedList)malloc(sizeof(LNode));
		s->data = value;
		//将s插到p之前
		s->next = p;
		q->next = s;
	} else {
		printf("插入失败！\n");
	}
}

//后插
void InsertAfter(LinkedList L, int pos, ElemType value)
{
	//在第pos个结点后插入结点，其值为value
	LinkedList p = L->next, s;
	int n = 1;
	//链表非空且未达到第pos个结点时
	while(p != NULL && n < pos)
	{
		//遍历下一个结点
		p = p->next;
		n++;
	}
	//找到第pos个结点
	if(p != NULL) {
		//申请新结点
		s = (LinkedList)malloc(sizeof(LNode));
		s->data = value;
		//将s插到p之前
		s->next = p->next;
		p->next = s;
	} else {
		printf("插入失败！\n");
	}
}	

//删除
void Delete(LinkedList L,int pos)
{
	//删除单链表的第pos个结点
	//指针q指向p的前驱结点
	LinkedList p = L->next, q = L;
	int n = 1;
	//链表非空且未达到第pos个结点时
	while(p != NULL && n < pos)
	{
		q = p;
		//遍历下一个结点
		p = p->next;
		n++;
	}
	//找到第pos个结点
	if( p != NULL) {
		//删除p结点
		q->next = p->next;
		//释放p所指的存储单元
		free(p);
	} else {
		printf("删除失败！\n\n");
	}
}

void main()
{
	LinkedList L;
	int pos;
	ElemType value;
	//创建
	L = Creat();
	printf("创建的链表是：\t");
	visit(L);
	printf("前插输入位置int pos和插入值int value: ");
	scanf("%d%d", &pos, &value);
	//前插
	InsertBefore(L, pos, value);
	printf("前插后的链表是:\t");
	visit(L);
	printf("后插输入位置int pos和插入值int value: ");
	scanf("%d%d", &pos, &value);
	//后插
	InsertAfter(L, pos, value);
	printf("后插后的链表是:\t");
	visit(L);
	printf("删除输入位置int pos: ");
	scanf("%d", &pos);
	//删除
	Delete(L, pos);
	printf("删除后的链表是:\t");
	visit(L);
}
