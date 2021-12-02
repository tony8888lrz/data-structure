#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
// SWU tony
typedef struct LNode //结点分为数据域与指针域
{
    int data;
    struct LNode *next;

}LNode, *LinkList;

void CreateList_L_head(LinkList &L,int n);//头插法
void CreateList_L_tail(LinkList &L,int n);//尾插法
void InsertElem_L(LinkList &L,int n,int m);// 接口说明:表明，位序，元素值
void DelElem_L(LinkList &L,int n);// 接口说明:表明，位序
void Print_list(LinkList &L);

int main(void)
{
    LinkList L,P;
    CreateList_L_tail(L,10);//尾插法
    CreateList_L_head(P,10);//头插法
    Print_list(L);    

    InsertElem_L(P,4,88);
    InsertElem_L(L,3,99);

    DelElem_L(L,4);
    DelElem_L(P,8);

    Print_list(L);
    Print_list(P);
}

void CreateList_L_head(LinkList &L,int n)//头插法
{
    L = (LinkList) malloc (sizeof(LNode)); //初始化头指针同时也是整个链表的地址
    L -> next = NULL; 
    LNode *p;
    for(int i = 0;i<n;i++)
    {
        p = (LinkList) malloc (sizeof(LNode));
        p -> data = i;
        p -> next = L ->next;
        L -> next = p;
    }//核心算法
}

void CreateList_L_tail(LinkList &L,int n)//尾插法
{
    L = (LinkList) malloc (sizeof(LNode)); //初始化头指针同时也是整个链表的地址
    LNode *s,*q=L;
    for(int i = 0;i<n;i++)
    {
        s = (LinkList) malloc (sizeof(LNode)); //每次创建新的结点
        s -> data = i;
        q -> next = s;
        q = s;
    }

    q ->next = NULL; //工具人指针使命结束
}

void Print_list(LinkList &L)
{
    LinkList p;
    p = L -> next;
    printf("linklist:\n");
    while(p)
    {
        printf("%i\n",p->data);
        p = p-> next;
    }
    printf("\n");
}

void InsertElem_L(LinkList &L,int n,int m)
{
    LNode *p,*s;
    int j = 0;
    p = L;

    while(p && j<n-1) //寻找到第n-1 个结点
    {
        p = p -> next;
        j++;
    }

    s = (LinkList) malloc (sizeof(LNode)); //分配新的结点空间
    s ->data = m;
    s ->next = p ->next;
    p -> next = s; //插入算法
    printf("your insert elem is %i\n",m);

}

void DelElem_L(LinkList &L,int n)
{
    LNode *p,*s;
    int j = 0,Del;
    p = L;

    while(p && j<n-1) //寻找到第n-1 个结点
    {
        p = p -> next;
        j++;
    }

    s = p -> next;
    p -> next = s ->next;
    Del = s->data;// 删除算法

    printf("your del elem is %i\n",Del);
    free(s);

}