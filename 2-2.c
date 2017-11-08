#include <stdio.h>
#define	MAXSIZE 100

typedef int DataType;

typedef struct node
{
	DataType data[MAXSIZE + 1];
	int last;
}SequList;

// 创建顺序表
void Creat(SequList *a)
{
	DataType x;
	int i=0;
	printf("创建顺序表,输入若干整数(int),-1作为结束: ");
	scanf("%d", &x);
	while(x!=-1)
	{
		i++;
		a->data[i] = x;
		// 输入下一个数据
		scanf("%d", &x);
	}
	// 记录数据个数（即表长）
	a->last = i;
}

// 顺序表排序
void Sort(SequList *a)
{
	int i,j;
	DataType temp;
	// 选择排序
	for(i = 1; i < a->last; i++) {
		for(j = i+1; j <= a->last; j++) {
			if(a->data[i] > a->data[j]) {
				temp = a->data[i],
				a->data[i] = a->data[j],
				a->data[j] = temp;  
			}
		}
	}
}

// 按输入值大小插入
void OrdInsert(SequList *a, DataType value)
{
	// 从第一个元素开始
	int i,pos = 1;
	//设置监视哨
	a->data[a->last+1] = value;
	while(value > a->data[pos]) {
		pos++;
	}
	//查找插入位置
	for(i = a->last; i >= pos; i--) {
		//数据元素移动
		a->data[i+1] = a->data[i];
	}
	//插入数据
	a->data[pos] = value;
	//修改表长
	a->last++;
}

//遍历顺序表
void Visit(SequList L)
{
	int i;
	for(i = 1; i <= L.last; i++) {
		printf("%5d", L.data[i]);
	}
	printf("\n\n");
}

void main()
{
	DataType value;
	SequList L;
	//创建顺序表
	Creat(&L);
	printf("创建后的顺序表:");
	Visit(L);
	Sort(&L);
	printf("排序后的顺序表:");
	Visit(L);
	printf("输入要插入的数据int value: ");
	scanf("%d", &value);
	//插入
	OrdInsert(&L, value);
	printf("插入后的链表:");
	Visit(L);
}
