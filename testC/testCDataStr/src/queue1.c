//ARRAY IMPLEMENTATION OF QUEUE (LINEAR)
#define MAX_SIZE 101
#include "common.h"

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
    return rear==MAX_SIZE-1 ? true : false;
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
        rear=rear+1;
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
        front=front+1;
    }
}

/*
static int Front(){
    return A[front];
}
*/

static void Print(){
    int i=0;
    printf("Queue: ");
    for(i=front; i<=rear; i++)
        printf("%d ",A[i]);
    printf("\n");
}

int Queue1(void){
    
    Enqueue(2); Print();
    Enqueue(5); Print();
    Enqueue(10); Print();
    Dequeue(); Print();
    Enqueue(12); Print();

    return 0;
}
