#include <stdio.h>
#include <stdlib.h>
//merge linked list
struct Node
{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

void Display (struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    
    printf("\n");
}

void Create(int A[], int n)
{
    int i=0;
    struct Node *t=NULL, *last=NULL;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for(i=1; i < n; i++)
    {
       t = (struct Node*)malloc(sizeof(struct Node));
       t->data = A[i];
       t->next = NULL;
       last->next = t;
       last = t;    
    }
}

void Create2(int A[], int n)
{
    int i=0;
    struct Node *t=NULL, *last=NULL;
    
    second = (struct Node*)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    
    for(i=1; i < n; i++)
    {
       t = (struct Node*)malloc(sizeof(struct Node));
       t->data = A[i];
       t->next = NULL;
       last->next = t;
       last = t;    
    }
}
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last = NULL;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next = NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next = NULL;
        }
    }
    
    if(p)last->next=p;
    if(q)last->next=q;
}

int main(void)
{
    int A[]={10,20,40,50,60};
    int B[]={15,18,25,30,55};

    Create(A,5);
    Create2(B,5);

    Merge(first,second);
    Display(third);
    
    return 0;
}
