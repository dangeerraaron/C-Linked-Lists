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
   
   printf("\n");
}
int RDisplayTail(struct Node *p) //tail recursion
{
    if(p != NULL)
    {
        printf("%d ", p->data); //print data stored in address of first node
        RDisplayTail(p->next); //call function to the next node
    }
    printf("\n");
}
int RDisplayHead(struct Node *p) //head recursion
{
   if(p != NULL)
   {
       RDisplayHead(p->next); //function call to next node
       printf("%d ",p->data); //print linked List IN REVERSE
   }
} 
int CountNode(struct Node *p)
{
    int l=0;  // number of nodes initialized to zero
    while(p != NULL)
    {
       l=l+1; // increment # of nodes
       p=p->next; //advance pointer to next node
    }
    
    return l; // returns the number of nodes in linked list
}

int Rcount(struct Node *p)
{
  if(p != NULL)
     return Rcount(p->next) + 1;
  
  else
     return 0;
}
int SumList(struct Node *p)
{
    int sum=0;
    while(p != NULL)
{
    sum = sum + p->data; //adds element each node and stores in sum
    p=p->next; // move pointer to next node
}
    return sum;
}

int RSumList(struct Node *p) // recursive sum
{
    if(p == NULL)
        return 0;
    else
        return RSumList(p->next) + p->data;
        // function call to node and add data elements on return
} 

int maximum(struct Node *p) // iterative max element
{
    int max = -32768; // assign smallest value for max
    while(p != NULL)
    {
      if(p->data > max)
          max = p->data; //assign data to max if condition true
          p=p->next; //move pointer to next node
    }
    
return max;
}

int Rmax(struct Node *p) //recursive max element
{
    int x=0;

    if(p==NULL)
        return -2147483648;
    x = Rmax(p->next);
    if(x > p->data)
        return x;
    else
        return p->data;
} 
struct Node * Lsearch(struct Node *p, int key)
{
    while(p != NULL)
    {
        if(key == p->data)
           return p;
        p=p->next;
    }
return NULL;
}
struct Node * RLsearch(struct Node *p, int key)
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return RLsearch(p->next, key);

}
struct Node * MHLsearch(struct Node *p, int key)
{
  struct Node *q; //create q pointer, tail pointer
    while(p != NULL)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;

           return p;
        }
        q=p;
        p=p->next;
    }
return NULL;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i=0;
    
    if(index < 0 || index > CountNode(p))
    {
        return;
    }
    
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    
    if(index == 0) // insert at front
    {
        t->next = first;
        first = t;
        
    }else{
           for(i=0; i < index-1; i++)
           {
               p=p->next;
           }
           t->next=p->next;
           p->next = t;
         }
}

int main(void)
{
  struct Node *temp; //store return type in temp
  int A[]={3,5,7,10,15,8,12,20};
  
  CreateNode(A,8);
  DisplayNode(first); //passes first global pointer to display function, accepts parameter as *p
  
  RDisplayTail(first); //prints in order
  RDisplayHead(first); //prints in reverse order
  
  
  printf("\nLength is %d nodes", CountNode(first)); //counts and displays number of nodes in list, insert Rcount function for recursive approach
  
  printf("\nThe sum of the linked list value = %d", SumList(first)); //insert RsumList for recursive approach
  printf("\nMax value = %d", Rmax(first));
  
  temp = RLsearch(first, 20); // assign search function, with linked list and key to temp

if(temp)
{
    printf("\nKey is found %d \n", temp->data);
}else{
         printf("\nKey is not found.\n");
     }  
     
 Insert(first, 3, 88);
 DisplayNode(first);        
    return 0;
}
