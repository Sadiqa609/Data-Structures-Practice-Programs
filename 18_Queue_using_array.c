#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int front;
    int rear;
    int*array;
};
int isEmpty(struct queue *ptr){
    if (ptr->rear==ptr->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct queue *ptr){
    if (ptr->rear==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue*ptr,int val){
    if(isFull(ptr)){
        printf("The Queue is Full");
    }
    else
    {
        ptr->rear=ptr->rear+1;
        ptr->array[ptr->rear]=val;
    }
}
int dequeue(struct queue*ptr){
    int val=-1;
    if(isEmpty(ptr)){
        printf("The Queue is Empty");
    }
    else
    {
        ptr->front=ptr->front+1; //or  ptr->front++;
        val=ptr->array[ptr->front];
    }
    return val;
}
int main(){
    struct queue q;
    q.size=50;
    q.front=-1;
    q.rear=-1;
    q.array=(int *)malloc(q.size*sizeof(int));
    //Enqueue elements in the queue
    enqueue(&q,12);
    enqueue(&q,14);
    enqueue(&q,16);
    printf("Dequeuing the element %d\n",dequeue(&q));
    printf("Dequeuing the element %d\n",dequeue(&q));
    // check either queue is empty or not
    if(isEmpty(&q)){
        printf("Queue is empty");
    }
    if(isFull(&q)){
        printf("Queue is Full");
    }
    return 0; 
}