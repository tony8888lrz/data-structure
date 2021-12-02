#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct 
{
    char *base;
    char *top;
    int stacksize;
}SqStack;

void InitStack(SqStack &S) //初始化
{
    S.base = (char *)malloc(100 * sizeof(char));
    if(!S.base)
        exit(1);
    S.top = S.base;
    S.stacksize = 10;
}

void Push(SqStack &S,char e)
{
    if(S.top - S.base >= 10)//判断是否满栈
        S.base = (char *)realloc(S.base,110*sizeof(char));
        if(!S.base)
            exit(1);
        S.top = S.base + S.stacksize;
        S.stacksize += 10;
    
    *S.top ++ = e; //先赋值再自增
}

void Pop(SqStack &s)
{
	s.top--;
	s.stacksize--;
}

void BracketMatch(SqStack &s)
{
	char c;
	while((c = getchar() ) != '\n'){
		if(c == '(')  
            Push(s, c);    //压入更急迫的元素

		else if(c == ')')
        {
			if(*(s.top - 1) == '(')      //找到匹配的括号，栈顶元素出栈
				Pop(s);
			else
            {
				printf("Match False!");
				exit(0);
			}
		}
	}
	if(s.top == s.base) 
        printf("Match Succeed!");       //最后检查条件
	else
	    printf("Match False!");
}



int main(void)
{
    SqStack s;  
    InitStack(s);
    BracketMatch(s);
}