// CircularLinkedListInsert
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; //self ref pointer

}*Head; // global pointer

void Create(int A[], int n)
{
    int i=0; // loop counter
    struct Node *t, *last; // temp pointer
    Head = (struct Node *)malloc(sizeof(struct Node)); //create head node

    Head->data = A[0]; // enter first array element into head node
    Head->next = Head; // head points to self circular
    last = Head; // last points to head

   for(i=1; i < n; i++)
   {
       t = (struct Node *)malloc(sizeof(struct Node)); // create new node for each data
       t->data = A[i];
       t->next = last->next; // circular link to last
        last->next = t; //point to t
        last = t; //move last pointer to t

    }

}
void Display(struct Node *h)
{
    do
    {
      printf("%d ",h->data);
      h=h->next;

    }while(h!=Head);

    printf("\n");

}
int Length(struct Node *p)
{
  int len=0;

  do
  {
      len=len + 1;
      p=p->next;

  }while(p != Head);

  return len;
} 
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i=0;
    if(index < 0 || index > Length(p))
        return;

    if(index == 0) // if first node inserted
    {
        t=(struct 
        Node*)malloc(sizeof(struct Node));
        t->data=x;

        if(Head == NULL)
        {
            Head=t; // t point to head
            Head->next=Head; //heead point to head
        }
        else
        {
            while(p->next != Head)p=p->next;
            p->next=t;
            t->next=Head;
            Head=t;
        }
    }
    else
    {
      for(i=0; i < index-1; i++)p=p->next;
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
int main(void)
{
    int A[] = {2,3,4,5,6};
    Create(A,5);
    
    Insert(Head,2,10);
    Display(Head);

    return 0;
}   
