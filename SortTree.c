#include <stdio.h>
#include <stdlib.h>
#define N 6

typedef int KeyType;

typedef struct node
{
    KeyType key;
    struct node *left,*right;
}BSTNode, *BSTree;

// 结点的插入 
void InsertBST(BSTree *Tptr, KeyType key)
{
    BSTNode *f, *p = *Tptr;
    while(p != NULL)
    {
        if(p->key == key) {
            return;
        }
        f = p;
        p = (key < p->key) ? p->left : p->right;
    }
    p = (BSTNode *)malloc(sizeof(BSTNode));
    p->key = key;
    p->left = p->right = NULL;
    if(*Tptr == NULL) {
        *Tptr = p;
    } else if(key < f->key) {
        f->left = p;
    } else {
        f->right = p;
    }
}

// 树的创建 
BSTree CreateBST(int n, KeyType R[])
{
    int i;
    BSTree T = NULL;
    for(i = 0; i < n; i++) {
        InsertBST(&T, R[i]);
    }
    return T;
}

// 树的删除 
BSTNode *DelBSTNode(BSTNode *Tptr, KeyType key)
{
    BSTNode *p = Tptr, *f = NULL, *s, *q;
    while(p != NULL)
    {
        if(p->key == key) {
            break;
        }
        f = p;
        if(p->key > key) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    if(p == NULL) {
        return Tptr;
    }
    if(p->left == NULL) {
        if(f == NULL) {
            Tptr = p->right;
        } else if(f->left == p) {
            f->left = p->right;
        } else { 
            f->right = p->right;
        }
        free(p);
    } else {
        q = p;
        s = p->left;
        while(s->right != NULL) {
            q = s;
            s = s->right;
        }
        if(q == p) {
            q->left = s->left;
        } else {
            q->right = s->left;
        }
        p->key = s->key;
        free(s);
    }
    return Tptr;
}

// 树的查找 
BSTNode *SearchBST(BSTree T, KeyType key)
{
    if(T == NULL || key == T->key) {
        return T;
    }
    if(key < T->key) {
        return SearchBST(T->left, key);
    } else { 
        return SearchBST(T->right, key);
    }
}

// 树的遍历 
void InOrder(BSTree p)
{
    if(p != NULL)
    {
        InOrder(p->left);
        printf("%5d", p->key);
        InOrder(p->right);
    }
}

void main()
{
    int i;
    KeyType data;
    KeyType a[N] = {67,24,78,53,12,99};
    BSTree root;
    printf("\nCreate Tree:");
    for(i = 0; i < N; i++) {
        printf("%5d", a[i]);
    }
    printf("\n  Sort Tree:");
    root = CreateBST(N, a);
    InOrder(root);
    printf("\n\nInput Search Data: ");
    scanf("%d", &data);
    if(SearchBST(root, data) != NULL) {
        printf("%d is found!\n", data);
    } else {
        printf("%d is not found!\n", data);
    }
    printf("\nInput Deleted Data: ");
    scanf("%d", &data);
    printf("\nAfter Delete:");
    root = DelBSTNode(root, data);
    InOrder(root);
    printf("\n");
    getchar();
}
