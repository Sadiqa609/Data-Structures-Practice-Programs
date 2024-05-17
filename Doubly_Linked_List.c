#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};
void TraversalDoublyLinkedList(struct Node*head){
    struct Node*ptr;
    while (ptr->next!=NULL)
    {
        printf("Elements in the Doubly linked lists are :%d\n", ptr->data);
        ptr=ptr->next;
    }
}     
int main(){
    //dynamic allocation of storage in heap
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    struct Node *n2=(struct Node*)malloc(sizeof(struct Node));
    struct Node *n3=(struct Node*)malloc(sizeof(struct Node));
    struct Node *n4=(struct Node*)malloc(sizeof(struct Node));
    //assigning  values and making connections
    head->data=12;
    head->prev=NULL;
    head->next=n2;
    n2->data=13;
    n2->prev=head;
    n2->next=n3;
    n3->data=14;
    n3->prev=n2;
    n3->next=n4;
    n4->data=15;
    n4->prev=n3;
    n4->next=NULL;
    //printf("Elements of the doubly linked list are : %d\n");
    TraversalDoublyLinkedList(head);
}