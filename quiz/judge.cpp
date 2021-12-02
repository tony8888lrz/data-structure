#include<stdio.h>
#define ERROR 0
#define OK 1
#define MAX_SIZE 10000

typedef struct NODE
{
    int arr[MAX_SIZE];
    int top;
}Node;

void init(Node &s) //初始化栈
{
    s.top = 0;
}

int pushElem(Node &s,int c) //入栈函数
{
    if(s.top == MAX_SIZE)
      return ERROR;
    s.arr[s.top++] = c;
    return OK;
}

int popElem(Node &s,int &e) //出栈函数
{
    if(s.top == 0)
      return ERROR;
    e = s.arr[--s.top];
    return OK;
}

int getTop(Node &s,int &e) //取栈顶元素
{
    if(s.top == 0)
      return ERROR;
    e = s.arr[s.top - 1];
    return OK;
}

int isEmpty(Node &s) //判断是否空栈
{
    return s.top == 0;
}

int test(int *enter,int *target)
{
    Node s;
    int ch;
    init(s);
    while(*enter != '\0'){
      pushElem(s,*enter);//将压栈字符串中的字符压入栈中
      //获取栈顶元素
      getTop(s,ch);

      while(ch == *target){
          // 如果相等，则出栈
          popElem(s,ch);
          target++;//后移
          getTop(s,ch);
      }
      enter++;//指针后移
    }

    if(*target != '\0')
      return 0;
    return 1;
}

void input(int *arr,int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
      printf("Please enter %i elements:",i+1);
      scanf("%d",&arr[i]);
    }
}

int main()
{
    int enter[10000],target[10000];
    int n,judge;

    printf("Number of Stack:");
    scanf("%d",&n);
    input(enter,n);//输入string A
    input(target,n);//输入string B
    judge = test(enter,target);//判断

    if(judge)
      printf("yes");
    else
      printf("no");
    return 0;
}

