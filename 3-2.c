#include <stdio.h>

void bin(int n) 
{
	if(n/2 > 0) {
		bin(n/2);
	}
	printf("%d", n%2);
}

void main()
{
	int n;
	printf("输入一个十进制整数：");
	scanf("%d", &n);
	printf("%d---->", n);
	bin(n);
	printf("\n");
}