#include <stdio.h>
#include <malloc.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct 
{
	int *elem;
	int length;
	int listsize;
}SqList;

void InitList_Sq(SqList &L)
{
	L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	/*if(!L.elem)
	{
		exit(0);
	}*/
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;

}

void ValList_Sq(SqList &L)
{

	for(int i = 0;i<=10;i++)
	{
		L.elem[i] = i;
		L.length++;
	}
}

void ListInsert_Sq(SqList &L,int i,int e)
{
	int *q,*p;
	q = L.elem;
	/*if(i<1 || i>L.length +1)
	{
		return 0;
	}*/
	if(L.length >= L.listsize)
	{
		L.elem = (int *)realloc(L.elem,(L.listsize + LISTINCREMENT) * sizeof(int));
		L.listsize += LISTINCREMENT;
	}

	q = &(L.elem[i-1]);   //q指针指向插入位置
	for(p = &L.elem[(L.length - 1)];p>=q;--p)
	{
		*(p+1) = *p;
	}

	*p = e;
	++L.length;
}

void ListDel_Sq(SqList &L,int i)
{
	int *q,*p;
	q = L.elem;
	/*if(i<1 || i>L.length +1)
	{
		return 0;
	}*/
	p = &(L.elem[i-1]);   //q指针指向删除位置
	q = L.elem+L.length - 1；
	for(++p ; p<=p ; ++p)
	{
		*(p+1) = *p;
	}
	L.length --;
}

int main(void)
{
	SqList L;
	InitList_Sq(L);
	ValList_Sq(L);
	
	printf("\n");
	ListInsert_Sq(L,2,33);
	ListDel_Sq(L,2); 
	for(int j =0;j<11;j++)
	{
		printf("%i\n",L.elem[j]);
	} 
}