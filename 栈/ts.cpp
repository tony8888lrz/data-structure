#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100//存储空间初始分配量 
#define STACKINCREMENT 10//分配增量
typedef int Status;
typedef char ElemType;
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}sqStack; 
Status InitStack(sqStack &s){
	s.base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s.base){
		exit(1);
	}
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return 0;
}
ElemType GetTop(sqStack s){//获取栈顶元素 
	ElemType e;
	if(s.top==s.base){
		return 0;
	}
	e=*(s.top-1);
	return e;
}
Status Push(sqStack &s,ElemType e){//插入元素e为新的栈顶元素 

	if(s.top-s.base>=s.stacksize){//如果栈满，扩充空间 
		s.base = (ElemType *)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!s.base){
		exit(1);
		}
		s.top=s.base+s.stacksize; 
		s.stacksize+=STACKINCREMENT;
	}
	*s.top++=e;//赋值后栈顶指针+1 
	return 0;
}
Status Pop(sqStack &s,ElemType &e){//删除栈顶元素 
	if(s.top==s.base){
		return 1;
	}
	e = *--s.top;//栈顶指针-1，给e赋值 
	return 0;
}
Status In(ElemType c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='#'||c=='('||c==')'||c=='['||c==']')
        return 1;
    else
        return 0;
}//In
char Precede(ElemType a, ElemType b){//判断运算符栈的 栈顶元素a和读入元素b的优先级 
    if(a=='+'||a=='-'){
        if(b=='+'||b=='-'||b=='>'||b=='#'||b==')'||b==']')
            return '>';
        else return '<';
    }
    if(a=='*'||a=='/'){
        if(b=='('||b=='[')
            return '<';
        else return '>';
    }
    if(a=='('){
        if(b==')')
            return '=';
        else return '<';
    }
    if(a=='['){
        if(b==']')
            return '=';
        else return '<';
    }
    if(a=='#'){
        if(b=='#')
            return '=';
        else return '<';
    }
}//Precede
char Operate(char a, char x, char b)
{//进行运算的函数 
    switch (x)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
}//Operator
ElemType EvaluateExpression(){
	sqStack OPTR,OPND;//OPTR:运算符栈 OPND:运算数栈 
	char c,x;
	InitStack(OPTR);
	Push(OPTR,'#'); 
	InitStack(OPND);
	c=getchar();
	
	while(c!='#'||GetTop(OPTR)!='#'){

		if(!In(c)){
			Push(OPND,c-'0'); //不是运算符，进入运算数栈。 
			c=getchar();
		}
		else
			switch(Precede(GetTop(OPTR),c)){
				case '<':Push(OPTR,c);c=getchar();break;//栈顶元素优先级低 
				case '=':Pop(OPTR,x);c=getchar();break;//栈顶元素优先级低 
				case '>':
				Pop(OPTR,x);
				char a, b;
                Pop(OPND, b);
				Pop(OPND, a);
				Push(OPND, Operate(a, x, b));
				break;
			}
	}
	return GetTop(OPND);
}
int main(){
	printf("The result:%d",EvaluateExpression());
	return 0;
}
