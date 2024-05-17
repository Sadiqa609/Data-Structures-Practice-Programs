#include<stdio.h>
#include<stdlib.h> // to use malloc fun
struct stack{
    int size;
    int top;
    int *array;
};
int isFull(struct stack * ptr){
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack*ptr){
    if (ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
void push(struct stack *ptr,int val){
    if (isFull(ptr))
    {
        printf("Stack Overflow  Cannot Push %d to the stack\n",val);
    }
    else
    {
        ptr->top++;
        ptr->array[ptr->top]=val;
    }
}
int pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!  Cannot Pop element from the stack\n");
    }
    else
    {   
        int val = ptr->array[ptr->top];
        ptr->top--;
        return val;
    }
}
int main(){
    struct stack * s=(struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top=-1;
    s->array=(int *)malloc(s->size*(sizeof(int)));
    printf("Before Pushing element in Stack%d\n");
    printf("Before Pushing , Empty = %d\n",isEmpty(s));
    printf("Before Pushing , Full = %d\n",isFull(s));
    push(s,12);
    push(s,22);
    push(s,32);
    push(s,42);
    push(s,52);
    push(s,62);
    push(s,72);
    push(s,82);
    push(s,92);
    push(s,102); //-->pushed 10 elements in the stack
    push(s,103); // -->Stack Overflow because the size of stack is 10
    printf("After Pushing element in Stack%d\n");
    printf("After Pushing , Empty = %d\n",isEmpty(s));
    printf("After Pushin , Full = %d\n",isFull(s));
    printf("Popped %d from the stack",pop(s));
    return 0;
}