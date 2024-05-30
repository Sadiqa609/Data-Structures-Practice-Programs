#include<stdio.h>
#include<stdlib.h>
struct circularqueue{
    int size;
    int front;
    int rear;
    int*array;
};
int isEmpty(struct circularqueue *ptr){
    if (ptr->rear==ptr->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct circularqueue *ptr){
    if ((ptr->rear+1)%ptr->size == ptr->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct circularqueue*ptr,int val){
    if(isFull(ptr)){
        printf("The circularqueue is Full");
    }
    else
    {
        ptr->rear=(ptr->rear+1)%ptr->size;
        ptr->array[ptr->rear]=val;
        printf("Enqued element: %d\n", val);
    }
}
int dequeue(struct circularqueue*ptr){
    int val=-1;
    if(isEmpty(ptr)){
        printf("The circularqueue is Empty");
    }
    else
    {
        ptr->front=(ptr->front+1)%ptr->size; //or  ptr->front++;
        val=ptr->array[ptr->front];
    }
    return val;
}
int main(){
    struct circularqueue q;
    q.size = 4;
    q.front = q.rear = 0;
    q.array = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
 
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
 
    return 0;
}