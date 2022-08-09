#include <stdio.h>
#include <stdlib.h>

//check if linked list is a loop

struct Node
{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;

void display(struct Node *p)
{
    while(p !=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void create(int A[], int n) // enter data from array index
{
    struct Node *t, *last;
    int i=0;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last=first;
    
    for(i=1; i < n; i++)
    {
       t = (struct Node *)malloc(sizeof(struct Node));
       t->data = A[i];
       t->next = NULL;
       last->next = t;
       last = t;
    }
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p=q=f; // set all pointers to first node

    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;

    }while(p && q && p!= q); // while p and q not null and p is not equal to q
    if(p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    struct Node *t1, *t2;
    
    int A[]={10,20,30,40,50};
    
    create(A,5);
    
   t1=first->next->next;
   t2=first->next->next->next->next;
   t2->next=t1;  // 5th node points to 3rd*/ 
    
    printf("%d \n", isLoop(first));
 
    return 0;   
}
