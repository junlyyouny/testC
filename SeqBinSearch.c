#include <stdio.h>
#define MAXSIZE 11

typedef int KeyType;

typedef struct
{
	KeyType key;
}ElemtType;

typedef struct
{
    ElemtType elem[MAXSIZE+1];
    int n;
}SqTable;

void SeqSearch(SqTable R, KeyType k)
{ 
    int i;
    // 监视哨  
    R.elem[0].key = k; 
    i = R.n;
    while(R.elem[i].key != k) {
        i--;
    }
    if(i != 0) {
        printf("关键字%d顺序查找的次序是： %d\n", k, i);
    } else {
        printf("关键字%d顺序查找失败!\n", k);
    }
}

void BinSearch(SqTable R, KeyType k)
{
    int low = 1, high = R.n, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(R.elem[mid].key == k) {
            printf("关键字%d二分查找的次序是%d\n", k, mid);
            return;
        } else if(R.elem[mid].key < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("关键字%d二分查找失败!\n", k);
}

void main()
{
    int i;
    KeyType key;
    SqTable a = {
        {0,4,12,18,23,36,55,63,76,81,89,93},
        11
    };
    printf("顺序表: ");
    for(i = 1; i <= a.n; i++) {
        printf("%5d", a.elem[i].key);
    }
    printf("\n");
    printf("输入查找关键字: ");
    scanf("%d", &key);
    SeqSearch(a, key);
    printf("\n");
    BinSearch(a, key);
}
