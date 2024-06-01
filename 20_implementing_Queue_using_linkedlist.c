#include <stdio.h>
#include <stdlib.h>
//declaring the structure of Nodes
struct Node * front=NULL; // declaring globaly for ease
struct Node * rear=NULL;
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *node)
{
    printf("Printing the elements of the linked list\n");
    while (node != NULL)
    {
        printf("Elements in the linked lists are :%d\n", node->data);
        node = node->next;
    }
}
void enqueue(int val){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    if (n==NULL)
    {
        printf("Queue is FULL\n");
    }
    else
    {
        n->data=val;
        n->next=NULL;
        if (front==NULL) // check if queue is empty
        {
            front=rear=n;
        }
        else
        {
            rear->next=n;
            rear=n;
        }
        
    }
    
}
int dequeue(){
    int value =-1;
    struct Node*ptr=front;
    if (front==NULL)
    {
     printf("Queue is empty\n");
    }
    else{
        front=front->next;
        value=ptr->data;
        free(ptr);
    }
    return value;
}
int main(){
    linkedListTraversal(front);
    printf("Dequeuing element %d\n",dequeue()); //it return -1 bcz right here nothing in queue
    enqueue(12);
    enqueue(13);
    enqueue(14);
    printf("Dequeuing element %d\n",dequeue()); //it return first element 12 bcz it follows FIFO 
    linkedListTraversal(front);
}