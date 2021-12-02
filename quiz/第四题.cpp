#include <stdio.h>
#include <stdlib.h> 
typedef struct Node node;
struct Node
{ 
    int data; 
	node *next; 
}; 


void createList(node * head , node * tail ,  int n ) 
{ 
    if (n < 1) 
    { 
        head  =  NULL; 
    } 

    head ->data = 1; 
    head ->next = NULL ; 
     
    node * p = head ; 
     for ( int i = 2; i<n+1; i++) 
     { 
		p->next = (node*)malloc(sizeof(node));
        p = p ->next ; 
        p->data = i ; 
        p->next = NULL ; 
     } 
     
    tail = p; 
    p->next = head; 
} 

void Print (node * head ) 
{ 
    node * p = head ; 

    while (p && p ->next !=head) 
    { 
    	//printf ("%d ", p->data); 
        p =p ->next ; 
    } 

} 

void CountPrint (node * head , node * tail ,  int m ) 
{ 
    node * cur  = head ; 
    node * pre  = tail ; 
     
     int cnt = m - 1; 
     while (cur && cur!=cur->next) 
     { 
        if (cnt ) 
        { 
            cnt--; 
            pre = cur; 
            cur = cur->next ; 
        } 
        else 
        { 
            pre->next = cur->next; 
            free(cur); 
            cur = pre ->next ; 
            cnt = m-1; 
        }     
    } 

     if (cur) 
     { 
        printf ( "%d " , cur ->data ); 
        free(cur); 
        head = tail = NULL ; 
     } 
    printf ("\n"); 
} 

int main () 
{ 
    node * head = (node*)malloc(sizeof(node)); 
    node * tail = (node*)malloc(sizeof(node)); 
    int M; 
    int N;
	printf("Enter M,N: "); 
    scanf ( "%d" ,&N); 
    scanf ( "%d" ,&M); 
    createList(head,tail,N); 
    Print (head); 
    CountPrint(head,tail,M); 
    return  0; 
}


