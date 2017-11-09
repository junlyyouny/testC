#define MAXSTRSIZE 100
#include <stdio.h>

typedef struct
{
	char ch[MAXSTRSIZE+1];
	int len;
}SeqString;

//求串长
int StrLen(SeqString *str)
{
	int i = 0;
	while(str->ch[++i] != '\0') {
		str->len = i;
	}
	return str->len;
}

void StrConcat(SeqString *s, SeqString *t)
{
	int i, j;
	if(s->len + t->len <= MAXSTRSIZE)
	{
		i = 1;
		j = 1;
		while(j <= t->len)
		{
		    s->ch[s->len+i] = t->ch[j];
		    i++;
		    j++;
		}
	    s->len += t->len; 
    } else if(s->len < MAXSTRSIZE) {
		i = 1;
		j = 1;
		while(j <= MAXSTRSIZE - t->len)
		{
			s->ch[s->len + i] = t->ch[i];
			i++;
			j++;
		}
		s->len = MAXSTRSIZE;
	}
	s->ch[s->len + 1] = '\0';
}

void SubString(SeqString *sub, SeqString *s, int pos, int len)
{
	int i,j;
	if(pos < 1 || pos > s->len || len < 0 || len > s->len - pos + 1) {
    	printf("错误！\n");
	} else {
		i = 1;
		j = pos;
		while(i <= len)
		{
			sub->ch[i] = s->ch[j];
			i++;
			j++;
		}
		sub->len = len;
	}
	sub->ch[sub->len + 1] = '\0';
}

void main()
{
	int pos, sublen;
	SeqString s, t, *sp = &s, *tp = &t;
	printf("\n\n输入串s: ");
	gets(&s.ch[1]);
	printf("输入串t: ");
	gets(&t.ch[1]);
	printf("串s: ");
	puts(&s.ch[1]);
	printf("串s的长度:%d\n", StrLen(sp));
	printf("串t: ");
	puts(&t.ch[1]);
	printf("串t的长度:%d\n", StrLen(tp));
	StrConcat(sp, tp); 
	printf("串s+串t是: ");
	puts(&sp->ch[1]);
	printf("输入串s的起始位置pos和子串长sublen: ");
	scanf("%d%d", &pos, &sublen);
	SubString(tp, sp, pos, sublen);
	printf("子串: ");
	puts(&tp->ch[1]);
}
