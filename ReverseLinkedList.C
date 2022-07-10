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
void InsertSorted(struct Node *p, int x)
{
    struct Node *t, *q=NULL; //create pointer t and q, initialize q to NUll
    t = (struct Node *)malloc(sizeof(struct Node)); // node 't' created
   
    t->data = x; //assign key to data
    t->next = NULL; // t node points to NULL
    
    if(first == NULL)
        first = t; // if p or first very first node created, point to 't'
    else
    {    while(p && p->data < x)

        {
            q = p; // move q to p position
            p = p->next; //move p to next node
        }
        if(p==first) //insert data at node before first position
        {
            t->next = first;
            first = t;
        }
        else //insert between nodes
        {
            t->next = q->next; // t node points to q next position
            q->next = t; //q node now points to t
        }
    }

}
int Delete(struct Node *p, int index)
{
    struct Node *q=NULL; //tail pointer
    int x=-1; // store data before deletio
    int i=0;

    if(index < 1 || index > CountNode(p))
        return -1; // condition to check if link lost index valid
     if(index==1) // deletes first node
     {
        q=first;// q points to first
        x=first->data; // assign data in node to x
        first=first->next; // move pointer to next node
        free(q); // delete pointer to node
        return x;
     }
     else
     {
       for(i=0;i<index-1;i++)
       {
          q=p; //move q pointer one index
          p=p->next; // move p pointer to next
       }
       q->next=p->next; //move pointer to pnext
       x=p->data; // store data in x
       free(p); //deallocate p memory
       return x;
     }
}
int isSorted(struct Node *p)
{
    int x=-65536; //set comparison index to 0
    
    while (p != NULL)
    {
        if(p->data < x)
        {
            return 0;
        }
        x = p->data; //store p-data in x
        p=p->next; //move pointer to next node
    } 
    return 1;
}
void Reverse1(struct Node *p)
{
    int *A, i=0;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*CountNode(p)); // dynamic array bases on size of linked list
    
    while(q != NULL)
    {
        A[i]=q->data; // copy q data into auxillary array
        q=q->next; // move pointer to next node
        i++; //increment i to next array index
    }
    q=p; // start q at p, beginning of linked list
    i--; // start at last element of array
    while(q != NULL)
    {
        q->data=A[i]; //copy array index into q Node
        q=q->next;
        i--;
    }
}
void Reverse2(struct Node *p)
{
   struct Node *q=NULL, *r=NULL; //moving pointers
   
   while(p != NULL)
   {
       r=q; // move r to q position
       q=p; // move q to p position
       p=p->next; //move p to next node
       q->next=r; // point q back to r
   }
   first=q; //first points to q
}
void Reverse3(struct Node *q, struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next); //recursive call
        p->next=q; 
    }
    else
    {
        first=q;
    }
}
int main(void)
{
  struct Node *temp; //store return type in temp
  int A[]={3,5,7,10,15,8,12,20};
  
  CreateNode(A,8);
  /*DisplayNode(first); //passes first global pointer to display function, accepts parameter as *p
  
   RDisplayTail(first); //prints in order
   RDisplayHead(first); //prints in reverse order
  
  
  printf("\nLength is %d nodes", CountNode(first)); //counts and displays number of nodes in list,  insert Rcount function for recursive approach
  
  printf("\nThe sum of the linked list value = %d", SumList(first)); //insert RsumList for recursive approach
  printf("\nMax value = %d", Rmax(first));
  
  temp = RLsearch(first, 20); // assign search function, with linked list and key to temp

  if(temp)
  {
    printf("\nKey is found %d \n", temp->data);
  }else{
         printf("\nKey is not found.\n");
       } 
     
   Delete(first,3);
   DisplayNode(first);   */
 
 Reverse3(NULL,first);
 DisplayNode(first);
    return 0;
}
