#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct node
{
	DataType data;
	struct node *lchild, *rchild;
}BTree;

FILE *fp;

//先序递归创建
BTree *CreatTree()
{
	char x;
	BTree *t;
	x = fgetc(fp);
	if(x == '@') {
		return NULL;
	} else {
		t = (BTree *)malloc(sizeof(BTree));
		t->data = x;
		t->lchild = CreatTree();
		t->rchild = CreatTree();
		return t;
	}
}

//先序递归遍历
void PreOrder(BTree *bt)
{
	if(bt != NULL)
	{
		printf("%3c", bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

//先序非递归遍历
void PreOrder1(BTree *bt)
{
	BTree *s[100], *p = bt;
	int top = 0;
	while(p != NULL || top > 0)
	{
		while(p != NULL)
		{
			printf("%3c", p->data);
			s[++top] = p;
			p = p->lchild;
		}
		p = s[top--];
		p = p->rchild;
	}
}

//中序递归遍历
void InOrder(BTree *bt)
{
	if(bt != NULL)
	{
		InOrder(bt->lchild);
		printf("%3c", bt->data);
		InOrder(bt->rchild);
	}
}

//中序非递归遍历
void InOrder1(BTree *bt)
{
	BTree *s[MAXSIZE], *p = bt;
	int top = 0;
	while(p != NULL || top > 0)
	{
		while(p != NULL)
		{
			s[++top] = p;
			p = p->lchild;
		}
		p = s[top--];
		printf("%3c", p->data);
		p = p->rchild;
	}
}

//后序递归遍历
void PostOrder(BTree *bt)
{
	if(bt != NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%3c",bt->data);
	}
}

//后序非递归遍历
void PostOrder1(BTree *bt)
{
	BTree *s1[MAXSIZE], *p = bt;
	int s2[MAXSIZE], b, top = 0;
	do {
		while(p != NULL) 
		{
			s1[top] = p;
			s2[top++] = 0;
			p = p->lchild;
		}
		if(top > 0) {
			b = s2[--top]; 
			p = s1[top];
			if(b == 0) {
				s1[top] = p;
				s2[top++] = 1;
				p = p->rchild;
			} else {
				printf("%3c", p->data); 
				p = NULL;
			}
		}
	} while(top > 0);
}

//层次遍历
void LevelOrder(BTree *bt)
{
	BTree *q[MAXSIZE], *p;
	int front, rear;
	q[1] = bt;
	front = rear = 1;
	while(front<=rear)
	{
		p = q[front];
		front++;
		printf("%3c", p->data);
		if(p->lchild != NULL)
		{
			rear++;
			q[rear] = p->lchild;
		}
		if(p->rchild != NULL)
		{
			rear++;
			q[rear] = p->rchild;
		}
	}
}

void main()
{
	BTree *t;
	fp = fopen("6-2.dat", "r");
	printf("输入数据在文件中读出！\n\n");
	t = CreatTree();
	fclose(fp);
	printf("先序递归法遍历：");
	PreOrder(t);
	printf("\n");
	printf("先序非递归法遍历：");
	PreOrder1(t);
	printf("\n\n");
	printf("中序递归法遍历：");
	InOrder(t);
	printf("\n");
	printf("中序非递归法遍历：");
	InOrder1(t);
	printf("\n\n");
	printf("后序递归法遍历：");
	PostOrder(t);
	printf("\n");
	printf("后序非递归法遍历：");
	PostOrder1(t);
	printf("\n\n");
	printf("按层次遍历：");
	LevelOrder(t);
	printf("\n\n");
}
