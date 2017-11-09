#define MAXSTRSIZE 100
#include <stdio.h>

typedef char ArrString[MAXSTRSIZE+1];

//求串长
int StrLen(ArrString s)
{
	int i=1,n=0;
	while(s[i] != '\0')
	{
		i++;
		n++;
	}
	return n;
}

//串比较
int StrCompare(ArrString s, ArrString t)
{
	int i=1;
	while(s[i] != '\0' && t[i] != '\0')
	{
		if(s[i] != t[i]) {
			return s[i]-t[i];
		}
		i++;
	}
	return s[i]-t[i];
}

void main()
{
	ArrString s, t;
	printf("\n\n输入串s: ");
	gets(&s[1]);
	printf("输入串t: ");
	gets(&t[1]);
	printf("串s的长度是：%d\n", StrLen(s));
	printf("串t的长度是：%d\n\n", StrLen(t));
	if(StrCompare(s, t) < 0) {
		printf("串s<串t\n");
	} else if(StrCompare(s, t) > 0) {
		printf("串s>串t\n");
	} else {
		printf("串s=串t\n");
	}
}
