#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *node)
{
    while (node != NULL)
    {
        printf("Elements in the linked lists are :%d\n", node->data);
        node = node->next;
    }
}
// Case -1 Deleting the head node
struct Node *delectionatStart(struct Node*head)
{
    struct Node*ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
// Case -2 Deleting the node at index
struct Node *delectionatIndex(struct Node*head, int index)
{
    struct Node*p=head;
    struct Node*q=head->next;
    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
//Deleting the element at a given value
struct Node *delectionatValue(struct Node*head, int value)
{
    struct Node*p=head;
    struct Node*q=head->next;
    while (q->next!=NULL&&q->data!=value)    
    {
        p=p->next;
        q=q->next;
    }
    if (q->data==value)
    {
       p->next=q->next;
       free(q);
    }
    return head;
}

//Deleting the last element
struct Node *delectionatEnd(struct Node*head)
{
    struct Node*p=head;
    struct Node*q=head->next;
    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next; 
    }
    p->next=NULL;
    free(q);
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // dynamic memory allocation in heap for linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    // linking 1st node with 2nd node
    head->data = 1;
    head->next = second;
    // linking 2nd node with 3rd node
    second->data = 3;
    second->next = third;
    // linking third node with fourth
    third->data = 5;
    third->next = fourth;
    // Linked list termination
    fourth->data = 7;
    fourth->next = NULL;
    printf("Linked list before deletion : %d\n");
    linkedListTraversal(head);
    printf("This is the 1st case deletion at start : %d\n");
   // head=delectionatStart(head);// deleting 1st element
    //head=delectionatStart(head);// deleting 1st element
    //Deleting the node at index
    //printf("This is the second case deletion at index/in between nodes : %d\n");
    //head=delectionatIndex(head,2);
    //printf("This is the third case deletion at end : %d\n");
   // head=delectionatEnd(head);
    printf("This is the fourth case deletion at given : %d\n");
    head=delectionatValue(head,3);
    printf("Linked list After deletion : %d\n");
    linkedListTraversal(head);
    return 0;
}
