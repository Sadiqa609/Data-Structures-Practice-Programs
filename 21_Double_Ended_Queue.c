#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int front;
    int rear;
    int*array;
};
int isEmpty(struct queue *ptr){
    return(ptr->front==-1 && ptr->rear==-1);
}
int isFull(struct queue *ptr){
   return ((ptr->rear + 1) % ptr->size == ptr->front);
}

void enqueueFront(struct queue *ptr, int value) {
    if (isFull(ptr)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(ptr)) {
        ptr->front = 0;
        ptr->rear = 0;
    } else {
        ptr->front = (ptr->front - 1 + ptr->size) % ptr->size;
    }
    ptr->array[ptr->front] = value;
}
void enqueueRear(struct queue *ptr, int value) {
    if (isFull(ptr)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(ptr)) {
        ptr->front = 0;
        ptr->rear = 0;
    } else {
        ptr->rear = (ptr->rear + 1) % ptr->size;
    }
    ptr->array[ptr->rear] = value;
}
int dequeueFront(struct queue *ptr) {
    if (isEmpty(ptr)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int value = ptr->array[ptr->front];
    if (ptr->front == ptr->rear) {
        ptr->front = -1;
        ptr->rear = -1;
    } else {
        ptr->front = (ptr->front + 1) % ptr->size;
    }
    return value;
}
int dequeueRear(struct queue *ptr) {
    if (isEmpty(ptr)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int value = ptr->array[ptr->rear];
    if (ptr->front == ptr->rear) {
        ptr->front = -1;
        ptr->rear = -1;
    } else {
        ptr->rear = (ptr->rear - 1 + ptr->size) % ptr->size;
    }
    return value;
}
void printDeque(struct queue *ptr) {
    if (isEmpty(ptr)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = ptr->front;
    printf("Deque: ");
    while (i != ptr->rear) {
        printf("%d ", ptr->array[i]);
        i = (i + 1) % ptr->size;
    }
    printf("%d\n", ptr->array[i]);
}
int main(){
    struct queue dq;
    dq.size=50;
    dq.front=-1;
    dq.rear=-1;
    dq.array=(int *)malloc(dq.size*sizeof(int));
    //Enqueue elements in the queue
    enqueueRear(&dq, 1);
    enqueueRear(&dq, 2);
    enqueueFront(&dq, 3);
    printDeque(&dq);

    dequeueFront(&dq);
    printDeque(&dq);

    enqueueRear(&dq, 4);
    printDeque(&dq);

    dequeueRear(&dq);
    printDeque(&dq);
    if(isEmpty(&dq)){
        printf("Queue is empty");
    }
    if(isFull(&dq)){
        printf("Queue is Full");
    }
    return 0; 
}