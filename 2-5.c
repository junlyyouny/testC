#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	//系数
	int coef; 
	//指数
	int exp;
	struct node *next;
}PolyList;//多项式链表的类型名

//创建
PolyList *CreatList()
{
	PolyList *head, *r, *s;
	int co, ex;
	//建立头结点
	head = (PolyList*)malloc(sizeof(PolyList));
	head->next = NULL;
	//尾指针r初值指向头结点
	r = head;
	printf("成对输入多项式的系数和指数(int co,ex)，最后系数和指数9999作为结束：");
	scanf("%d%d", &co, &ex);
	while(co != 9999 && ex != 9999)
	{
 		//生成新结点s
		s = (PolyList *)malloc(sizeof(PolyList));
		//将新结点插入表尾
		s->coef = co;
		s->exp = ex;
		//尾指针r指向新的表尾
		r->next = s;
		r = s;
		//读入下一个结点值
		scanf("%d%d", &co, &ex);
	}
	//将尾结点的指针域置为空
	r->next = NULL;
	return head;
}

//遍历
void PrnList(PolyList *head)
{
	PolyList *p = head->next;
	int noden = 0;
	while(p != NULL)
	{
		switch(++noden)
		{
			//多项式的首项
			case 1: 
				//指数为0，1，>1
				switch(p->exp)
				{
					case 0: 
						printf("%d", p->coef);
						break;
					case 1: 
						//系数为-1，1，其它
						switch(p->coef)
						{
							case -1: 
								printf("-X");
								break;
							case 1: 
								printf("X");
								break;
							default: 
								printf("%dX", p->coef);
						}
						break;
					default:
						//系数为-1，1，其它
						switch(p->coef)
						{
							case -1:
								printf("-X**%d", p->exp);
								break;
							case 1:
								printf("X**%d", p->exp);
								break;
							default: 
								printf("%dX**%d", p->coef, p->exp);
						}
				}
				break;
			//多项式从第二项至末项
			default:
				switch(p->exp)
				{
					case 0:
						if(p->coef > 0) {
							printf("+%d", p->coef);
						} else {
							printf("%d", p->coef);
						}
						break;
					case 1: 
						switch(p->coef)
						{
							case -1:
								printf("-X");
								break;
							case 1: 
								printf("+X");
								break;
							default:
								if(p->coef > 0) {
									printf("+%dX", p->coef);
								} else {
									printf("%dX", p->coef);
								}
						}
						break;
					default:
						switch(p->coef)
						{
							case -1:
								printf("-X**%d", p->exp);
								break;
							case 1:
								printf("+X**%d", p->exp);
								break;
							default: 
								if(p->coef > 0) {
									printf("+%dX**%d", p->coef, p->exp);
								} else {
									printf("%dX**%d", p->coef, p->exp);
								}
						}
				}
		}
		p = p->next;
	}
	printf("\n\n");
}

//计算两个一元多项式相加
PolyList *PolyAdd(PolyList *pa, PolyList *pb)
{
	PolyList *qa = pa->next, *qb = pb->next, *qc = pa, *s;
	//qa指向链表pa中的结点，初始时指向第一个结点
	//qb指向链表pb中的结点，初始时指向第一个结点
	//利用pa所指链表头结点，作为“和多项式”的头结点，qc指向“和多项式”的尾结点
	while(qa != NULL && qb != NULL)
	{
		if(qa->exp > qb->exp) {
  			//将qa所指结点插入“和多项式”的尾部
			qc->next = qa;
			qc = qa;
			qa = qa->next;
		} else if(qa->exp < qb->exp) {
			//将qb所指结点插入“和多项式”的尾部
			qc->next=qb;
			qc = qb;
			qb = qb->next;
		} else {
			//系数相加，结果存于qa所指结点的系数域
			qa->coef += qb->coef;
			if(qa->coef != 0) {
				//将qa所指结点插入“和多项式”的尾部
				qc->next = qa;
				qc = qa;
				qa = qa->next;
				//删除qb所指结点，并释放存储单元
				s = qb;
				qb = qb->next;
				free(s);
			} else {
				//当系数为0
				//删除qa所指结点，并释放存储单元
				s = qa;
				qa = qa->next;
				free(s);
				//删除qb所指结点，并释放存储单元
				s = qb;
				qb = qb->next;
				free(s);
			}
		}
	}
	qc->next = NULL;
	//插入pa中剩余的结点
	if(qa != NULL) {
		qc->next = qa;
	}
	//插入pb中剩余的结点
	if(qb != NULL){
		qc->next = qb;
	}
	//释放pb所指的头结点
	free(pb);
	return pa;
}

void main()
{
	PolyList *pa, *pb;
	printf("生成pa单链表");
	pa = CreatList();
	printf("pa单链表: ");
	PrnList(pa);
	printf("生成pb单链表");
	pb = CreatList();
	printf("pb单链表: ");
	PrnList(pb);
	//两个一元多项式相加
	pa = PolyAdd(pa, pb);
	printf("pa+pb单链表: ");
	PrnList(pa);  
}
