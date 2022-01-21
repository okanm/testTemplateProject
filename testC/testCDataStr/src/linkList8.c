//REVERSE A LINK LIST (Recursion Approach)
//we will literally reverse here
//head global variable
#include "common.h"

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

static void Reverse(struct Node* p){
    if(p->next==NULL){
        head = p;
        return;
    }  //Exit condition
    Reverse(p->next);
    struct Node* q = p->next;
    q->next=p;
    p->next=NULL;}

static struct Node* Insert(struct Node *head, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if (head==NULL) head=temp;
    else{
        struct Node* temp1 = head;
        while (temp1->next!=NULL) temp1=temp1->next;
        temp1->next=temp;   
    }
    return head;
}
static void Print()
{
    struct Node* temp=head;
    printf("List is: ");
    while (temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int LinkList8(void)
{    
    head=NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    Print();
    Reverse(head);
    Print();
    
    return 0;
}



