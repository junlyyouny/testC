#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node
{
	int i, j;
	union
	{
		DataType v;
		struct node *next;
	}val;
    struct node *right, *down;
}MLink;

MLink *CreatMatrix( )
{
	MLink *p, *s, *hm, *head[MAXSIZE];
	int i, j, k, m, n, t, max;
	DataType v;
	FILE *fp;
	fp = fopen("5-2.dat", "r");
	fscanf(fp, "%d%d%d", &m, &n, &t);
	printf("行数=%d,列数=%d,非0元素的个数=%d\n\n", m, n, t);
	if(m > n) {
		max = m;
	} else {
		max = n;
	}
	hm = (MLink *)malloc(sizeof(MLink));
	hm->i = m;
	hm->j = n;
	head[0] = hm;
	// 生成表头结点的循环链表 
	for(k = 1; k <= max; k++)
	{
		s = (MLink *)malloc(sizeof(MLink));
		s->i = 0;
		s->j = 0;
		s->right = s;
		s->down = s;
		head[k] = s;
		head[k-1]->val.next = s;
	}
	head[max]->val.next = hm;
	printf("矩阵三元表：\n");
	for(k=1;k<=t;k++)
	{
		fscanf(fp, "%d%d%d", &i, &j, &v);
		printf("%d\t%d\t%d\n", i, j, v);
		s = (MLink *)malloc(sizeof(MLink));
		s->i = i;
		s->j = j;
		s->val.v = v;
		p = head[i];
		while(p->right != head[i] && p->right->j < j) {
			p = p->right;
		}
		s->right = p->right;
		p->right = s;
		p = head[j];
		while(p->down != head[j] && p->down->i < i) {
			p = p->down;
		}
		s->down = p->down;
		p->down = s;
	}
	fclose(fp);
	return hm;
}

void main()
{
	MLink *head;
	head = CreatMatrix();
}
