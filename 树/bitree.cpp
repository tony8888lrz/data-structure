#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct BiNode
{
    char data;
    struct BiNode *lchild, *rchild;
}BiNode, *BiTree;

void CreateBiTree(BiTree &T);
void PreOrderTraverse(BiTree &T);
void InOrderTraverse(BiTree &T); //in
void PostOrderTraverse(BiTree &T); //Post


int main(void)
{
    char e;
    BiTree T;
    CreateBiTree(T);
    printf("PreOrder:");
    PreOrderTraverse(T);
    printf("InOrder:");
    InOrderTraverse(T);
    printf("PostOrder:");
    PostOrderTraverse(T);
}

void CreateBiTree(BiTree &T)
{
    char ch;
    scanf("%c",&ch);
    if(ch == ' ')
        T = NULL;
    else
    {
        if(!(T = (BiNode *)malloc(sizeof(BiNode)))) //先分配空间后判断
            exit(1);
        T -> data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
void PreOrderTraverse(BiTree &T) //pre
{
    if(T)
    {
        printf("%c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void InOrderTraverse(BiTree &T) //in
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        printf("%c",T->data);
        InOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree &T) //Post
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c",T->data);
    }
}

