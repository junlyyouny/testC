#include <stdio.h>
#include <stdlib.h>
#define	MAXSIZE 100

typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SeqList;

SeqList L;

// 判空表
int empty(void)
{
	return(!L.length);
}

// 创建顺序表
void creat(void)
{
	int i = 0;
	ElemType x;
	printf("创建顺序表,输入若干整数int,  -1作为结束:");
	scanf("%d", &x);
	while(x != -1)
	{
		L.data[i] = x ;
		scanf("%d", &x);
		i++;
	}
	// 记录数据个数（即表长）
	L.length = i;
}

// 遍历
void visit(void)
{
	int i;
	if(empty()) {
		printf("空表");
	} else {
		for(i=1; i<=L.length; i++) {
			printf("% 5d", L.data[i-1]);
		}
	}
	printf("\n表长是：%d\n\n", L.length);
}

// 插入
void insert(int i, ElemType b)
{
	int j;
	if(L.length == MAXSIZE) {
		printf("表满，无法插入");
		exit(0);
	}
	if(i<1 || i>L.length) {
		printf("插入位置i非法\n");
		exit(0);
	}
	for(j = L.length-1; j >= i-1; j--) {
		// 元素后移
		L.data[j+1] = L.data[j];
	}
	// 在第i个位置上插入b
	L.data[i-1] = b;
	// 表长加1  
	L.length++;
}

// 删除
void deletes(int i)
{
	int j;
	if(i<1 || i>L.length) {
		printf("删除位置i非法\n");
		exit(0);
	}
	for( j=i; j <= L.length-1; j++) {
		// 元素前移
		L.data[j-1]=L.data[j];
	}
	// 表长减1
	L.length--;
}

void main()
{
	int i;
	ElemType x;
	// 创建
	creat();
	printf("创建后的顺序表L:");
	visit();
	printf("输入插入位置int i和数据int x:");
	scanf("%d%d", &i, &x);
	// 插入
	insert(i, x);
	printf("插入后的顺序表L:");
	visit();
	printf("输入删除位置int i:");
	scanf("%d", &i);
	// 删除
	deletes(i);
	printf("删除后的顺序表L:");
	visit();
}