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
    linkedListTraversal(head);
    return 0;
}
