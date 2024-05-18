#include <stdio.h>
#include <stdlib.h>
// This program only tells the balancing of paranthesis regardless of teh validity of expression
struct stack{
    int size;
    int top;
    char * arr; // pointer to dynamically allocate memory for the array
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
void push(struct stack *ptr,char val){
    if (isFull(ptr))
    {
        printf("Stack Overflow  Cannot Push %d to the stack\n",val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
char pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!  Cannot Pop element from the stack\n");
    }
    else
    {   
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int paranthesis_Matching(char*exp){
    //creating stack
    struct stack* ptr;
    ptr->size=200; // here i am taking size = 200 bcz of the ease but when you are dealing with other projects you 
    ptr->top=-1;   // may use strlen function to find the size of your expression
    ptr->arr=(char *)malloc(ptr->size*(sizeof(char)));
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(ptr,'(');
        }
        else if(exp[i]==')')
        {
            if(isEmpty(ptr))
            {
                return 0;
            }
            pop(ptr);
        }
    }
    if (isEmpty(ptr))
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int main(){
    char *exp="2*(6))";
    if (paranthesis_Matching(exp))
    {
       printf("The paranthesis is matching %d");
    }
    else
    {
       printf("The paranthesis is not matching %d");
    }
    
    return 0;
}