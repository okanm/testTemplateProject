// LINKED LIST IMPLEMENTATION OF QUEUE 
#include "common.h"

struct Node{
    int data;
    struct Node *next;
};

static struct Node* front=NULL;
static struct Node* rear=NULL;

static void Enqueue(int x){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    //if queue is empty
    if (front==NULL && rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}

static void Dequeue(){
    struct Node* temp=front;
    //if list is empty
    if (front==NULL){
        printf("Queue is Empty\n");
        return;
    }
    if (front==rear){
        front = rear = NULL;
    }
    else{
        front=front->next;
    }
    free(temp);
}

static int Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	return front->data;
}

static void Print(){
    struct Node* temp=front;
    printf("Queue is: ");
    while (temp!=NULL){
        printf(" %d", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int Queue3(void){
    
    Enqueue(2);Print();
    Enqueue(4);Print();
    Enqueue(6);Print();
    Dequeue();Print();
    Enqueue(8);Print();
    return 0;
}
