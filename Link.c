#include <stdio.h>
#include <stdlib.h>
#define KeyN 10
#define ListN 13
#define H1 Key[i] % 13

typedef int ElemType;

typedef struct Lnode
{
	ElemType data;
	struct Lnode *next;
}LN;

void creat(int m, ElemType Key[], LN *HT[])
{
	int i, j;
	ElemType k;
	LN *s;
	for(i = 0; i < m; i++) {
		HT[i] = NULL;
	}
	for(i = 0; i < m; i++)
	{
		j = H1;
		s = (LN *)malloc(sizeof(LN));
		s->data = Key[i];
		s->next = HT[j];
		HT[j] = s;
	}
}

void find(LN *HT[], ElemType k)
{
	int j = k % 13;
	LN *p = HT[j];
	while(p != NULL && p->data != k) {
		p = p->next;
	}
	if(p != NULL) {
		printf(" is found!\n");
	} else {
		printf(" isn't found!\n");
	}
}

void main()
{
	ElemType k;
	int i;
	LN *ht[ListN];
	ElemType KEY[KeyN] = {18,16,24,1,78,19,55,10,11,89};
	printf("\nKeys:");
	for(i = 0; i < KeyN; i++) {
		printf("%5d", KEY[i]);
	}
	creat(ListN, KEY, ht);
	printf("\n\nInput Key: ");
	scanf("%d", &k);
	printf("%d", k);
	find(ht, k);
}
