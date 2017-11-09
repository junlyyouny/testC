#define MAXSTRSIZE 100
#include <stdio.h>

typedef struct
{
	char str[MAXSTRSIZE+1];
	int length;
}SeqString;

//注意字符串是从s[1]和p[1]开始
SeqString s = {" ababcdbbcdacba", 14}, p={" bcdac", 5};

int SimpleMatching(SeqString *s, SeqString *p)
{
	int i, j, k, m = s->length, n = p->length;
	for(k = 1; k <= m-n+1; k++)
	{
		i = k;
		j = 1;
		while(j <= n && s->str[i] == p->str[j])
		{
			i++;
			j++;
		}
		if(j > n) {
			//第k趟匹配成功
			return k;
		}
	}
	//匹配不成功
	return -1;
}

void main()
{   
	int pos;
	pos = SimpleMatching(&s, &p);
	if(pos != -1) {
		printf("子串的位置是：%d\n", pos);
	} else {
		printf("匹配失败！\n");
	}
}
