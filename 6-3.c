#define MAX 100
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int age;
	char name[20];
}DataType;

typedef struct node
{
	DataType data;
	struct node *lchild, *rchild;
}BTree;

FILE *fp;

int TotalAge, TotalNumber;
BTree *CreateTree();
void Traversing(BTree *t);
void PreOrder(BTree *t);
void NodeLevel(BTree *t, int h, DataType x);
void OutPutLevelNode(BTree *t, int h);
void visitstring(BTree *t, int h);

void main()
{
	BTree *root;
	DataType x;
	int h;
	fp = fopen("6-3.dat", "r");
	root = CreateTree();
	fclose(fp);
	TotalAge = 0;
	TotalNumber = 0;
	PreOrder(root);
	if(TotalNumber == 0)
	{
		printf("\n家族为空！\n");
		exit(0);
	}
	printf("一、家族的平均年龄：%.2f\n", (float)TotalAge/TotalNumber);
	printf("\n二、输入要查找的家族成员的年龄：");
	scanf("%d", &x.age);
	printf("年龄为%d的的家族成员：\n姓名   年龄   辈份\n", x.age);
	NodeLevel(root, 1, x);
	printf("\n三、输入辈份：");
	scanf("%d", &h);
	printf("辈份为%d的所有家族的成员：\n姓名   年龄   辈份\n", h);
	if(h > 0) {
		OutPutLevelNode(root, h); 
	}
	printf("\n");
}

//层次创建二叉树
BTree *CreateTree()
{
	BTree *root, *s;
	DataType pp;
	root = NULL;
	fscanf(fp, "%d%s", &pp.age, pp.name);
	if(pp.age != 0)
	{
		s = (BTree *)malloc(sizeof(BTree));
		s->data = pp;
		s->lchild = CreateTree();
		s->rchild = CreateTree();
		root = s;
	}
	return root;
}

//年龄求和
void Traversing(BTree *t)
{
	TotalAge += t->data.age;
	TotalNumber++;
}

//输出姓名和年龄
void visitstring(BTree *t, int h)
{
	printf("%s%6d%6d\n", t->data.name, t->data.age, h);
}

//先序查找
void PreOrder(BTree *t)
{
	if(t != NULL)
	{
		Traversing(t);
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}

//层次遍历统计年龄
void NodeLevel(BTree *t, int h, DataType x)
{
	if(t != NULL)
	{
		if(t->data.age == x.age) {
			visitstring(t, h);
		}
		NodeLevel(t->lchild, h+1, x);
		NodeLevel(t->rchild, h+1, x);
	}	
}


//层次遍历输出
void OutPutLevelNode(BTree *t, int h)
{
	BTree *s[MAX];
	int i, begin, last, level, num;
	begin = 1;
	last = 1;
	level = 1;
	num = 1;
	s[last] = t;
	while(level < h)
	{
		for(i = 1; i <= num; i++)
		{
			if(s[begin]->lchild != NULL)
			{
				last++;
				s[last] = s[begin]->lchild;
			}
            if(s[begin]->rchild != NULL)
			{
				last++;
				s[last] = s[begin]->rchild;
			}
			begin++;
		}
		num = last - begin + 1;
		level++;
	}
	for(i = begin; i <= last; i++) {
		visitstring(s[i], h);
	}
}
