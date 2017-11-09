#include <stdio.h>
#define MAXSIZE 100

typedef int DataType;

typedef struct node
{
	DataType data[MAXSIZE+1];
	int top;
}SeqStack;//构造一个顺序栈

//构造空栈
void InitStack(SeqStack *s)
{
	s->top = 0;
}

//判栈空
int IsEmpty(SeqStack *s)
{
	//栈空时返回1，非空时为0
	return s->top == 0;
}

//入栈
void Push(SeqStack *s, DataType x)
{
	if(s->top == MAXSIZE) {
		printf("栈上溢出\n");
	} else {
		s->data[++s->top] = x;
	}
}

//出栈
DataType Pop(SeqStack *s)
{
	if(IsEmpty(s)) {
		printf("栈下溢出\n");
		return 0;
	} else {
		//返回栈顶元素值，top--
		return s->data[s->top--];
	}
}

//十化二
void Conversion(int n)
{
	int v;
	SeqStack s;
	InitStack(&s);
	while(n != 0)
	{
		Push(&s, n%2);
	 	n/=2;
	}
	while(!IsEmpty(&s))
	{
	 	v = Pop(&s);
	 	printf("%d", v);
	}
}

void main()
{
	int n;
	printf("输入一个十进制整数：");
	scanf("%d", &n);
	printf("%d---->", n);
	Conversion(n);
	printf("\n");
}
