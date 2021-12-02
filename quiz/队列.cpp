#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//222020321102007 廖润泽
int z[100001];
int x[100001];
int y[100001];

typedef struct NODE
{
	int mark;
	int leap;
	struct NODE *next; 
}NODE;

int main(void)
{
	int i;
	int N,M,ans;
	scanf("%d",&N);
	for(i=2;i<=N;i++)
		scanf("%d%d",&x[i],&y[i]);

	scanf("%d",&M);

	for(i=1;i<=M;i++)
	{
		scanf("%d",&ans);
		z[ans]++;
	}

	struct NODE *head=(struct NODE*)malloc(sizeof(struct NODE)); //初始化指针
	struct NODE *p=(struct NODE*)malloc(sizeof(struct NODE));

	p->next=NULL;
	head->next=p;
	p->mark=1;

	if(z[1]==0)
		p->leap=1;
	else
		p->leap=0;

	for(i=2;i<=N;i++)
	{
		struct NODE *stu=(struct NODE*)malloc(sizeof(struct NODE));
		stu->mark=i;
		stu->next=NULL;
	
		if(z[i]==0)
			stu->leap=1;
		else
			stu->leap=0;
	
		p=head;
		while(p->next)
		{
			if(p->next->mark==x[i])
				break;
			p=p->next;
		}

		if(y[i]==1)
			p=p->next;
		stu->next=p->next;
		p->next=stu;
	}
	
	p=head->next;
	while(p)
	{
		if(p->leap==1)
			printf("%d ",p->mark);
		p=p->next;
	}
}
