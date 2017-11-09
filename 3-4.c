#include <stdio.h>
#include <math.h>
#define MAXSIZE 100

typedef char DataType;

typedef struct node
{
	DataType data[MAXSIZE+1];
	int top;
}SeqStack;// 运算符栈   

typedef int _DataType;

typedef struct _node
{
	_DataType data[MAXSIZE+1];
	int top;
}_SeqStack;// 操作数栈

//运算符栈初始化
void InitStack(SeqStack *s)
{
	s->top = 0;
}

//操作数栈初始化
void _InitStack(_SeqStack *s)
{
	s->top = 0;
}

//运算符入栈
void Push(SeqStack *s, DataType x)
{
	if(s->top == MAXSIZE) {
		printf("栈上溢!\n");
	} else {
		s->data[++s->top] = x;
	}
}

//操作数入栈
void _Push(_SeqStack *s, _DataType x)
{
	if(s->top == MAXSIZE) {
		printf("栈上溢!\n");
	} else {
		s->data[++s->top] = x;
	}
}

//运算符栈判空(yes=1,no=0)
int IsEmpty(SeqStack *s)
{
	return s->top == 0;
}

//操作数判栈空(yes=1,no=0)
int _IsEmpty(_SeqStack *s)
{
	return s->top == 0;
}

//取运算符栈顶元素
DataType GetTop(SeqStack *s)
{
	if(IsEmpty(s)) {
		printf("栈空!\n");
		return 0;
	} else {
		return s->data[s->top];
	}
}

//取操作数栈顶元素
_DataType _GetTop(_SeqStack *s)
{
	if(_IsEmpty(s)) {
		printf("栈空!\n");
		return 0;
	} else {
		return s->data[s->top];
	}
}

//运算符出栈
DataType Pop(SeqStack *s)
{
	if(IsEmpty(s)) {
		printf("栈下溢!\n");
		return 0;
	} else {
		return s->data[s->top--];
	}
}

//操作数出栈
_DataType _Pop(_SeqStack *s)
{
  if(_IsEmpty(s)) {
  		printf("栈下溢!\n");
  		return 0;
  	} else {
  		return s->data[s->top--];
  	}
}

//运算符的优先级
int precede(char oper) 
{
	switch(oper)
	{
		case '=': 
			return 0;
		case '+':
		case '-': 
			return 1;
		case '*':
		case '/': 
		case '%': 
			return 2;
		case '^': 
			return 3;
	}
}

//计算结果
int operate(int x, char oper, int y)
{
	switch(oper)
	{
		case '+':
			return x+y;
		case '-':
			return x-y;
		case '*':
			return x*y;
		case '/':
			if(y != 0) {
				return x/y;
			} else {
				printf("除数分母为0！\n");
			}
		case '%':
			return x%y;
		case '^':
			return pow(x, y);
	}
}

//表达式计算
int calc()
{
	SeqStack oper_s; _SeqStack num_s;
	char ch, op;
	int x, y;
	InitStack(&oper_s);
	Push(&oper_s, '=');
	_InitStack(&num_s);
	printf("输入表达式,=作为结束: ");
	scanf("%c", &ch);
	while(ch != '=' || GetTop(&oper_s) != '=') {
		if(ch >= '0' && ch <= '9') {
			_Push(&num_s, ch-'0');
			scanf("%c", &ch);
		} else if(precede(ch) > precede(GetTop(&oper_s))) {
			Push(&oper_s, ch);
			scanf("%c", &ch);
		} else {
			op = Pop(&oper_s);
			y = _Pop(&num_s);
			x = _Pop(&num_s);
			_Push(&num_s, operate(x, op, y));
		}
	}
	return _GetTop(&num_s);
}

void main()
{
	printf("表达式的结果是：%d\n", calc());
}