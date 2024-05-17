#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int * arr; // pointer to dynamically allocate memory for the array
};
//to check either the stack is empty
int isEmpty(struct stack*ptr)
{
    if (ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack*ptr)
{
    if (ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(){
    //method 1 to implement 
    // struct stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=(int *)malloc(s.size*(sizeof(int)));
    //method 2 to implement using pointer 
    //the benefit of using pointer is that we
    // can access functions thats why i used this method
    struct stack *s;
    s->size=80;
    s->top=-1;
    s->arr=(int *)malloc(s->size*(sizeof(int)));
    //just to check isempty function i just manually pushed the value in stack
   // s->arr[0]=9;
    //s->top++;  
    if (isEmpty(s))
    {
       printf("The stack is empty %d");
    }
    else
    {
       printf("The stack is not empty %d");
    }
    //performing push operation
    if(isFull(s))
    {
        printf("The stack is full%d");
    }
    else
    {
        printf("The stack is not full%d");
    }
    
    return 0;
}