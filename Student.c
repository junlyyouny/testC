#include <stdio.h>
#define N 5

typedef struct
{
	int num;
	char name[10];
	char sex;
	int age;
	float grade;
}ST;

ST stu[N] = {
		{1, "Peter", 'M', 25, 88.5},
		{2, "Mary", 'W', 20, 77.0},
		{3, "Tom", 'M', 19, 66.0},
		{4, "Tarry", 'M', 19, 99.5},
		{5, "Jan", 'W', 22, 88.0}
	};

void print()
{
	int i;
	printf("    Num   Name   Sex   Age   Grade\n");
	for(i = 0; i < N; i++) {
		printf("%6d    %-8s%c%6d%8.1f\n", 
			stu[i].num,
			stu[i].name,
			stu[i].sex,
			stu[i].age,
			stu[i].grade
		);
	}
}

void Select(int k)
{
	int i, j;
	ST s;
	for(i = 0; i < N-1; i++) {
		for(j = i+1; j < N; j++) {
			switch(k)
			{
				case 1:
					if(strcmp(stu[i].name, stu[j].name) > 0) {
						s = stu[i], stu[i] = stu[j], stu[j] = s;
					}
					break;
				case 2:
					if(stu[i].age > stu[j].age) {
						s = stu[i], stu[i] = stu[j], stu[j] = s;
					}
					break;
				case 3:
					if(stu[i].grade < stu[j].grade) {
						s = stu[i], stu[i] = stu[j], stu[j] = s;
					}
					break;
			}
		}
	}
}

void main()
{
	printf(" Num:\n\n");
	print();
	printf("\n");
	getchar();
	printf(" Name:\n\n");
	Select(1);
	print();
	printf("\n");
	getchar();
	printf(" Age:\n\n");
	Select(2);
	print();
	printf("\n");
	getchar();
	printf(" Grade:\n\n");
	Select(3);
	print();
	printf("\n");
	getchar();
}
