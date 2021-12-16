#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define m  (2*8-1)  //leaf number
#define MAXVALUE 1000 

typedef struct
{
    int weight;
    int parent,lchild,rchild;
}HTNode, *HuffmanTree;

typedef char ** HuffmanCode; //writing in book
/*typedef char* HCNode;
typedef HCNode* HuffmanCode;in the same way*/

void Select_HT(HuffmanTree &HT,int p,int &s1,int &s2)
{
    int i; 
    int min1=1000; 
    int min2=1000;
    
    for(i=1;i<=p;i++) //find s1
    {
        if(HT[i].parent==0 && min1>HT[i].weight)
        {
            min1=HT[i].weight;
            s1=i;
        }
    }

    for(i=1;i<=p;i++)//find s2 but a little bit stupid
    {
        if(i!=s1 && HT[i].parent==0)
            if(HT[i].weight<min2)
            {
                min2=HT[i].weight;
                s2=i;
            }
    } 
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC,int *w,int n)
{
    // 构建哈夫曼树
    int i,s1,s2;
    int start, c, f;
    char *code;
    for(i = 1;i<=n;++i)//weight assignment
    {
        printf("number %i:",i);
        scanf("%i",&w[i]);
    }

    HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode)); //assign the space to HT

    HT[0].weight = n; //0号位置
    
    for(i = 1;i<=m;i++) //initialize
    {
        HT[i].weight = w[i];
        HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0; 
    }

    
    for(i = n+1;i<=m;++i) //loop choose 2 minsnode,then combine a new one
    {
        Select_HT(HT,i-1,s1,s2); //pick the 2 mins node
        HT[s1].parent = HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight; //weight plus
    }

    /*for(i = 1;i<=m;i++) //debugging
    {
        printf("%i\n",HT[i].weight);
    }*/

    //---------------------------------------------------------huffmancode
    HC = (HuffmanCode)malloc((n+1)*sizeof(char *));
    code = (char *)malloc(n*sizeof(char));
    code[n-1] = '\0'; //reverse
    for(i=1; i<=n; i++)									 
	{
		start = n - 1;					// record the position			 
		for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c)
				code[--start] = '0';
			else
				code[--start] = '1'; //coding core
		}
		
		HC[i] = (char*)malloc((n-start)*sizeof(char)); //distribute the space
		
		strcpy(HC[i], &code[start]);					
	}
	free(code); // free the memory
    //printf("%s",HC[1]);debug
}

void ShowHuffmanTree_HT(HuffmanTree &HT)
{
	int i;
	
	printf("------------------------------------------\n");
	printf("--*order--weight--parent--lchild--rchild--\n");
	for(i=0; i<=2*HT[0].weight-1; i++)
	{
		if(i==0)
			printf("--  %2d  -- %4d --  --  --  --  --  --  --\n", i, HT[i].weight);
		else
			printf("--  %2d  -- %4d --  %2d  --  %2d  --  %2d  --\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	printf("------------------------------------------\n");
}

void ShowHuffmanCode_HT(HuffmanTree &HT, HuffmanCode &HC)
{
	int i;
	
	printf("------------------------------------------\n");
	printf("--*order--weight--      --  ----------  --\n");
	for(i=1; i<=HT[0].weight; i++)
		printf("--  %2d  -- %4d --------  %-14s--\n", i, HT[i].weight, HC[i]);	
	printf("------------------------------------------\n");
}


int main(void)
{
    HuffmanTree HT;
    HuffmanCode HC;
    int n = 8; //leaf node
    int *w;
    HuffmanCoding(HT,HC,w,n);
    ShowHuffmanTree_HT(HT);
    ShowHuffmanCode_HT(HT,HC);
}