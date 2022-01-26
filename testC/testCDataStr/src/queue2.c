// ARRAY IMPLEMENTATION OF QUEUE (CIRCULAR)
#include "common.h"
#define MAX_SIZE 101


//Global variables
static int A[MAX_SIZE];
static int front=-1;
static int rear=-1;

static bool isEmpty(){
    if (front==-1 && rear==-1){
        return true;
    }
    else{
        return false;
    }
}

static bool isFull(){
    return (rear+1)%MAX_SIZE == front ? true : false;
}

static void Enqueue(int x){
    if (isFull()){
        printf("Queue is full for %d\n", x);
        return;
    }
    else if (isEmpty()){
        front=0;
        rear=0;
    }
    else{
        rear=(rear+1)%MAX_SIZE;
    }
    A[rear]=x;
}
static void Dequeue(){
    if (isEmpty()){
        return;
    }
    else if (front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%MAX_SIZE;
    }
}

static int Front(){
    return A[front];
}

static void Print(){
    int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
    printf("Queue: ");
    for(int i = 0; i <count; i++){
        int index = (front+i) % MAX_SIZE;
        printf("%d ",A[index]);}
    printf("\n");
}

int Queue2(void){
    
    Enqueue(2); Print();
    Enqueue(5); Print();
    Enqueue(10); Print();
    Dequeue(); Print();
    Enqueue(12); Print();

    return 0;
}
