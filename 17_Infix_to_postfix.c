#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
        return -1;
    }
    else
    {   
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int stackTop(struct stack * ptr){
    return(ptr->arr[ptr->top]);
}
int precedence(char ch){
    // you may adjust the if else, if you have more operators other than these
    if(ch=='*' || ch =='/')
    {
        return 3;
    }
    else if(ch=='+' || ch =='-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int isOperator(char ch){
    if (ch=='+'||ch=='-'||ch=='*'||ch=='/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char* infixToPostfix(char* infix){
    struct stack*ptr=(struct stack *)malloc(sizeof(struct stack));
    ptr->size=10;//you can take any value or can find the size
    ptr->top=-1;
    ptr->arr=(char*)malloc(ptr->size*(sizeof(char)));
    char * postfix = (char*)malloc((strlen(infix)+1)*(sizeof(char)));
    int i=0;  //for infix traversal
    int j=0;  //for postfix traversal
    while (infix[i]!='\0')
    {
      if (!isOperator(infix[i]))
      {
        postfix[j]=infix[i];
        j++;
        i++;
      }
      else
      {
        if(precedence(infix[i])>precedence(stackTop(ptr)))
        {
            push(ptr,infix[i]);
            i++;
        }
        else{
            postfix[j]=pop(ptr);
            j++;
        }
      }
      
    }
    while (!isEmpty(ptr))
        {
            postfix[j]=pop(ptr);
            j++;
        }
        postfix[j]='\0';
        return postfix;
    
}
int main(){
    char * infix = "a-b+c/7";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}