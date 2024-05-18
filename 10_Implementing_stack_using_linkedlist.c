#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
    struct Node *top = NULL; //make it global in order to reflect changes anywhere in the top 
// Stack Traversal through Linked List
void linkedListTraversal(struct Node *node)
{
    while (node != NULL)
    {
        printf("Elements in the stack are  :%d\n", node->data);
        node = node->next;
    }
}
// to check either the stack is empty
int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Node *ptr)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// implementing push function on stack using linked list
int pop(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = ptr;
        top = ptr->next; // moving pointer to next of the top
        int value = n->data; // saving the data of top
        free(n);         // deleting or popping the top
        return value ;      // returning the value of the popped element
    }
}
struct Node *push(struct Node *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = val;
        n->next = ptr;
        ptr = n;
    }
}

int main()
{
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    int element = pop(top);
    printf("The Popped element is : %d\n", element);
    linkedListTraversal(top);
    return 0;
}