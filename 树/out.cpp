typedef struct{
 int weight;
 int parent;
 int lchild;
 int rchild;
}HTNode,*HuffmanTree;
void CreateHuffmanTree(HuffmanTree *HT,int n);
void Select(HuffmanTree HT,int m,int *s1,int *s2); 
void outHuffmanTree(HuffmanTree HT,int n);
#include<stdlib.h>
#include<stdio.h>
int main(){
 int n;
 HuffmanTree HT;
 
 printf("下面进行huffmantree的创建\n请输入你想要输入的结点个数:\n");
 scanf("%d",&n);
 CreateHuffmanTree(&HT,n);
 printf("创建Huffman tree完成\n");
 //printf("%d",HT[4].lchild);
 //printf("%d %d",4,HT[4].weight);测试发现应该是没有create成功 
 //printf("%d %2d %6d %6d %6d",4,HT[4].weight,HT[4].parent,HT[4].lchild,HT[4].rchild);//说明这个create不一定成功 
 //intf("%d",HT[3].weight);
 outHuffmanTree(HT,n);//HT里边的值就是那棵哈夫曼树的地址，这样就需要考虑之前的单链表，与2叉数的问题了 
 
 return 0;
}
void CreateHuffmanTree(HuffmanTree *HT,int n){
 if(n<=1)
  return;
 int i;
 int s1,s2;
 *(HT)=(HTNode*)malloc(2*n*sizeof(HTNode));//huffmantree有其他辅助结点 
 for(i=0;i<=2*n;i++){
  (*HT)[i].lchild=0;(*HT)[i].parent=0;(*HT)[i].rchild=0; 
 }
 printf("请输入这n个结点的weight："); 
 for(i=1;i<=n;i++)
  scanf("%d",&(*HT)[i].weight);
 for(i=n+1;i<2*n;i++){//进行n-1次的结合 //最后一个位置为2n-1 
  Select(*HT,i-1,&s1,&s2);//此时s1和s2里边就是那两个下标了，在下面的函数里边都是用到s1和s2而不是*s2 
  //select注意(*HT)因为你这个是在create函数里边，只有一个（*HT）它指向主程序里边一个变量，变量里的值就是那棵哈夫曼树的地址 
  //printf("%d,%d\n",s1,s2);//测试 
  (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
  (*HT)[s1].parent=i;
  (*HT)[s2].parent=i;
  (*HT)[i].lchild=s1;
  (*HT)[i].rchild=s2;
  //printf("%d\n",(*HT)[s1].parent);//测试 
 }
 
 
}
void Select(HuffmanTree HT,int m,int *s1,int *s2){//从这m个数里边选择最小的2个//把第一个进行标记就ok 
 int i;//从下标为1的位置开始计数 
 //int min=HT[1].weight;这里直接赋值不合理，假如第一次那个1就是最小被选选中，那么第2次还是被选中 
 int min1=1000; 
 int min2=1000;//规定一个特别大的数 
 
 for(i=1;i<=m;i++){
  if(HT[i].parent==0&&min1>HT[i].weight){
   min1=HT[i].weight;
   *s1=i;
  }
 }
 for(i=1;i<=m;i++){//注意这个I!=*s1标记min 
  if(i!=(*s1)&&HT[i].parent==0)
   if(HT[i].weight<min2){
    min2=HT[i].weight;
    *s2=i;
   }
  
 } 
}
void outHuffmanTree(HuffmanTree HT,int n){
 if(HT==NULL)
  printf("无huffmantree\n");
 int i;
 printf("输出huffmantree表格\n");
 printf("结点 weight parent lchild rchild\n");
 //printf("%d %2d %6d %6d %6d",i,HT[4].weight,HT[4].parent,HT[4].lchild,HT[4].rchild);//ceshi
 for(i=1;i<2*n;i++){//是2n-1个结点，申请了2n个位置0-2n-1（这是2n个用1-2n-1） 
  printf("%2d %6d %6d %6d %6d\n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
 }
 
}
