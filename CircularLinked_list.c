#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node*next;
};
void CircularLinkedListTraversal(struct Node*head)
{
    struct Node *node=head;
    do
    {
        printf("Elements in the Circular linked lists are :%d\n", node->data);
        node=node->next;
    } while (node!=head);
    
}

//case 01
struct Node *InsertionatFirst(struct Node*head,int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node*p=head->next;
    while (p->next!=head)
    {
        p=p->next;
    }
    //At this place p points to the last node which is actually
    //head in the circular linked list from here we are about to
    //perform insertion in the circular linked list
    p->next=ptr->next;
    ptr->next=head;
    head=ptr;
    return head;
}
//case 02
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
//case 03
struct Node* InsertatEnd(struct Node* head, int data)
{   // This is the new node which we insert at the end of LinkedList
    // This is dynamic memeory allocation in heap
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node*p =head;
    //ptr->data=data;
    do
    {
        p=p->next;
    } while (p!=head);
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;
    return ptr;
}
int main(){
    struct Node*head;
    struct Node*second;
    struct Node*third;
    struct Node*fourth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    head->data=1;
    head->next=second;
    second->data=3;
    second->next=third;
    third->data=5;
    third->next=fourth;
    fourth->data=7;
    fourth->next=head;
    printf("Elements before insertion in the Circular linked lists are :%d\n");
    CircularLinkedListTraversal(head);
   // head=InsertionatFirst(head,8);
    //CircularLinkedListTraversal(head);
    //head=InsertInBetween(head,2,2);
    //CircularLinkedListTraversal(head);
    head=InsertatEnd(head,80);
    printf("Elements after insertion in the Circular linked lists are :%d\n");
    CircularLinkedListTraversal(head);
    return 0;
}