
//REVERSE A LINKED LIST USING STACK
//Here, push the address of the nodes to the stack
#include "common.h"

struct Node {
    long long data;
    struct Node* next;
};

static struct Node* top;
static struct Node* head;

static void Push(void* x){
    struct Node* temp_p = (struct Node*)malloc(sizeof(struct Node));
    temp_p->data = x;
    temp_p->next = top;
    top=temp_p;
}

static void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if (head != NULL){
        struct Node* temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    } else {
        head=temp;
    } 
    Push(temp);
}

static void Print()
{
    struct Node* temp=head;
    printf("List is: ");
    while (temp!=NULL){
        printf(" %lld", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

static void Pop(){
    struct Node* temp;
    if (top==NULL) 
        return;
    temp=top;
    top=top->next;
    free(temp);
}

// we use stack here
static void Reverse() 
{
   head=top->data;
   struct Node* temp_r=top->data;
   Pop();
   while(top!=NULL){
       temp_r->next=top->data;
       Pop();
       temp_r=temp_r->next;
    }
    temp_r->next=NULL;
}

int Stack5(void){
    
    head=NULL;
    top=NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); //List: 2,4,6,5
    Print();
    Reverse();
    Print();

    return 0;
}
	
	
