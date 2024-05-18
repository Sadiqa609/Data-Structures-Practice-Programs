#include <stdio.h>
#include <stdlib.h>
//declaring the structure of Nodes
struct Node
{
    int data;
    struct Node *next;
};
//printing all the Nodes of the linked list
void linkedListTraversal(struct Node *node)
{
    while (node != NULL)
    {
        printf("Elements in the linked lists are :%d\n", node->data);
        node = node->next;
    }
}
//Case 01 : Insert at first node
struct Node* InsertatFirst(struct Node* head, int data)
{   // This is the new node which we insert at the start of LinkedList
    // This is dynamic memeory allocation in heap
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
//Case 02 : Insert in between of nodes
struct Node * InsertInBetween(struct Node*head,int data,int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node*p =head;
    int i=0;
    while (i!=(index-1))
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;
    return head;
}
//Case 03 : Insert at end node
struct Node* InsertatEnd(struct Node* head, int data)
{   // This is the new node which we insert at the end of LinkedList
    // This is dynamic memeory allocation in heap
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node*p =head;
    ptr->data=data;
    while (p->next!=NULL)
    {
        p= p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return ptr;
}
//Case 04 : Insert at specific node given to us
struct Node* InsertAtNode(struct Node* head,struct Node* prevNode, int data)
{   // This is the new node which we insert at the start of LinkedList
    // This is dynamic memeory allocation in heap
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next = prevNode->next;
    prevNode->next=ptr;
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
    head->data = 9;
    head->next = second;
    // linking 2nd node with 3rd node
    second->data = 1999;
    second->next = third;
    // linking third node with fourth
    third->data = 12;
    third->next = fourth;
    // Linked list termination
    fourth->data = 6;
    fourth->next = NULL;
    printf("  Linked list before Insertion : %d\n");
    linkedListTraversal(head);
    //head=InsertatFirst(head,56);
    //head=InsertInBetween(head,69,2);
    //head=InsertatEnd(head,89);
    head=InsertAtNode(head,second,18);
    printf("\nLinked list after Insertion\n");
    linkedListTraversal(head);
    return 0;
}
