// CircularLinkedList + Display
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
int main(void)
{
    int A[] = {2,3,4,5,6};
    Create(A,5);
    Display(Head);

    return 0;
}  
