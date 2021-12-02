#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
///222020321102007 廖润泽
#define Stack_Init_Size 100
#define STACK_SIZE_INCREASEMENT 10

typedef char Element;
typedef struct{
	Element *base;
	Element *top;
	int stacksize;
}SqStack;

void InitStack(SqStack & s){
	//构造一个栈s
	s.base = (Element * )malloc(Stack_Init_Size * sizeof(Element));
	if(!s.base) exit(0);
	s.top = s.base;
	s.stacksize = Stack_Init_Size;
}

void Push(SqStack & s, Element e)
{
	if(s.top - s.base >= Stack_Init_Size)
    {      //如果栈满，则增加栈的容量
		s.base = (Element *)realloc(s.base, (s.stacksize + STACK_SIZE_INCREASEMENT) * sizeof(Element));
		if(!s.base) exit(0);
		s.stacksize += STACK_SIZE_INCREASEMENT;
	}
	* s.top++ = e;
}

void Pop(SqStack & s){
	if(s.base == s.top) exit(0);
	else{
		s.top -= 1;
		s.stacksize -= 1;
	}
}

void BracketMatch(SqStack &s)
{
	char c;
	while((c = getchar() ) != '@'){
		if(c == '(')  
            Push(s, c);    //压入更急迫的元素

		else if(c == ')')
        {
			if(*(s.top - 1) == '(')      //找到匹配的括号，栈顶元素出栈
				Pop(s);
			else
            {
				printf("YES");
				exit(0);
			}
		}
	}
	if(s.top == s.base) 
        printf("YES");       //最后检查条件
	else
	    printf("NO");
}


int main()
{
	SqStack s;
	InitStack(s);
	BracketMatch(s);
	return 0;
}
