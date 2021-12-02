#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define n 4//树的叶子节点数
#define m  (2*n-1)//树的节点总数
#define MAXVALUE 1000 //权重最大值

typedef struct
{
    int weight;
    int parent,lchild,rchild;
}HTNode, *HuffmanTree;

//typedef char ** HuffmanCode;
typedef char* HCNode;
typedef HCNode* HuffmanCode;

void Select_HT(HuffmanTree &HT,int p,int *s1,int *s2)
{
    int i; 
    int min1=1000; 
    int min2=1000;//规定一个特别大的数 
    
    for(i=1;i<=p;i++) //find s1
    {
        if(HT[i].parent==0 && min1>HT[i].weight)
        {
            min1=HT[i].weight;
            *s1=i;
        }
    }

    for(i=1;i<=m;i++)//find s2
    {
        if(i!=(*s1) && HT[i].parent==0)
        if(HT[i].weight<min2)
        {
            min2=HT[i].weight;
            *s2=i;
        }
    } 
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC,int *w,int n)
{
    int i,s1,s2;
    int start, c, f;
    char *code;
    for(i = 1;i<=n;++i)//0号单元弃用,赋值
    {
        scanf("%i",w[i]);
    }

    //int m = 2*n - 1; // 有效节点个数
    HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode)); //0号单元弃用

    HT[0].weight = n; //0号单元存储个数
    
    for(i = 1;i<=m;i++) //initialize
    {
        HT[i].weight = w[i];
        HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0; 
    }

    for(i = n+1;i<=m;i++) //loop choose 2 minsnode,then combine a new one
    {
        Select_HT(HT,i-1,&s1,&s2);
        HT[s1].parent = HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

    //---------------------------------------------------------
    HC = (HuffmanCode)malloc((n+1)*sizeof(HCNode));
    code = (char*)malloc(n*sizeof(char));
    code[n-1] = '\0'; //逆序结尾
    for(i=1; i<=n; i++)									//逐次求每个叶子结点的哈夫曼编码 
	{
		start = n - 1;									//赋值起点 
		for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c)
				code[--start] = '0';
			else
				code[--start] = '1';
		}
		
		HC[i] = (char*)malloc((n-start)*sizeof(char));
		
		strcpy(HC[i], &code[start]);					//从start开始复制 
	}
	free(code);
}

void ShowHuffmanTree_HT(HuffmanTree &HT)
{
	int i;
	
	printf("┏━━━┳━━━┳━━━┳━━━┳━━━┓\n");
	printf("┃*order┃weight┃parent┃lchild┃rchild┃\n");
	for(i=0; i<=2*HT[0].weight-1; i++)
	{
		if(i==0)
			printf("┃  %2d  ┃ %4d ┃  ×  ┃  ×  ┃  ×  ┃\n", i, HT[i].weight);
		else
			printf("┃  %2d  ┃ %4d ┃  %2d  ┃  %2d  ┃  %2d  ┃\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	printf("┗━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}

void ShowHuffmanCode_HT(HuffmanTree &HT, HuffmanCode &HC)
{
	int i;
	
	printf("┏━━━┳━━━┳━━━┳━━━━━━━┓\n");
	printf("┃*order┃weight┃      ┃  哈夫曼编码  ┃\n");
	for(i=1; i<=HT[0].weight; i++)
		printf("┃  %2d  ┃ %4d ┃──→  %-14s┃\n", i, HT[i].weight, HC[i]);	
	printf("┗━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}


int main(void)
{
    HuffmanTree HT;
    HuffmanCode HC;
    //int n = 4;
    int w[4] = {7,8,6,4};
    HuffmanCoding(HT,HC,w,4);
}