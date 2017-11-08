#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node
{
	DataType data;
	struct node *next;
}LinkList;

//用尾插法创建链表
LinkList *CreatList()
{
	LinkList *head, *r, *s;
	DataType value;
	//建立头结点
	head = (LinkList*)malloc(sizeof(LinkList)); 
	head->next = NULL;
	//尾指针r初值指向头结点
	r = head;
	printf("生成单链表，输入若干数据int，-1作为结束：");
	scanf("%d", &value);
	while(value!=-1)
	{
		//生成新结点s
		s = (LinkList *)malloc(sizeof(LinkList)); 
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
	return head;
}

//遍历
void PrnList(LinkList *head) 
{
	LinkList *p = head->next;
	while(p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n\n");
}
	
//删除重复的结点
void DelNode(LinkList *head)
{
	//p从第一个数据结点开始
	LinkList *p = head->next, *q; 
	while(p->next != NULL)
	{
		//q指向p的后续结点
		q = p->next;
		//判断p和q的结点是否相同
		if(p->data == q->data) {
			//删除q所指的相同值结点
			p->next = q->next;
			free(q);
		} else {
			p=p->next;
		}
	}
}

//逆置单链表
void Invert(LinkList *head)
{
	//p从第一个数据结点开始
	LinkList *p = head->next, *q; 
	head->next = NULL;
	while(p != NULL)
	{
		//q指向当前的结点
		q = p;
		p = p->next;
		//将q结点插入到头结点之后
		q->next = head->next;
		head->next = q;
	}
}

void main()
{
	LinkList *head;
	//创建
	head = CreatList();
	printf("创建的链表是:");
	//创建后的遍历
	PrnList(head);
	//删除重复的结点
	DelNode(head);
	printf("删除重复结点后的链表是:");
	PrnList(head);
    //逆置单链表
    Invert(head);
	printf("逆置后的链表是:");
	//逆置后的遍历
	PrnList(head);
}
