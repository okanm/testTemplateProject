//INSERT NODE AT THE BEGINNING (head global variable)
#include "common.h"

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

static struct Node* GetNewNode (int x){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

static void InsertAtHead(int x){
    struct Node* newNode = GetNewNode(x);
     if (head == NULL){
         head = newNode;
         return;
     }
     head->prev=newNode;
     newNode->next=head;
     head=newNode;
}

static void Print()
{
    struct Node* temp = head;
    printf("Forward: ");
    while (temp!=NULL){
        printf(" %d", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

static void ReversePrint(){
    struct Node* temp=head;
    if (temp==NULL) return; // empty list, exit
    // Going to last Node
    while(temp->next !=NULL){
        temp=temp->next;
    }
    // Traversing backward using prev pointer
    printf("Reverse: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

int DLinkList2(void){
    
    head=NULL; //empty list
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
    
    return 0;
}
