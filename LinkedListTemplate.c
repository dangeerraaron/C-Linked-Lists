#include <stdio.h>
#include <stdlib.h>
//linked list practice/template
struct Node
{
int data;
struct Node *next;

}*first = NULL; //global pointer, init NULL

void CreateNode(int A[], int n)
{
   int i=0;
   struct Node *t, *last;
   first=(struct Node *)malloc(sizeof(struct Node)); //creating the first node, first pointing at it
   first->data = A[0]; //array index 0 assigned to node
   first->next = NULL; //assign null to terminal node
   last=first; //first and last node point to NULL
   
   for(i=1; i<n; i++) //for loop to store array elements in linked list, start from '1' as first node already created
   {
      t=(struct Node *)malloc(sizeof(struct Node)); //create a new node
      t->data=A[i]; //assign index to data of node struct
      t->next=NULL; //have next pointer to null, as no new node yet
      last->next=t; // last node points at t
      last=t; //t node becomes new node
   }   

}

void DisplayNode(struct Node *p)
{
   while(p != NULL) //iterate until null pointer
   {
      printf("%d ", p->data); //pointer to data in struct note, to print
      p=p->next; //move pointer to next node
   }
}
int main(void)
{
  int A[5]={3,5,7,10,15};
  
  CreateNode(A,5);
  DisplayNode(first); //passes first global pointer to display function, accepts parameter as *p
  
    return 0;
}

 
