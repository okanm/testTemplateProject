//DELETE NODE AT THE N-TH POSITION (head global variable)
//You have to fix the list and deallocate the memory of the deleted node
#include "common.h"

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

//define 3 functions
//void Insert(int data); //insert integer at the end of the list
//void Print();
//void Delete(int n); // delete n-th node

static void Insert(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
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
}

static void Print(){
    struct Node* temp=head;
    printf("List is: ");
    while (temp!=NULL){
        printf(" %d", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

static void Delete(int n)
{
    struct Node* temp1=head;
    
    //special case for removing head node 
    if (n==1){
        head=temp1->next; //head now points to the second node
        free(temp1);
        return; 
        //if you have this case (head node), you do not need to continue executing the code below. 
        //You can return here, or dont use 'return', use 'else' like if (n==1) .. else ...
    }
    
    int i;
    for (i=0; i<n-2; i++)
        temp1=temp1->next;
    //temp1 points to (n-1)th Node
    struct Node* temp2=temp1->next; //n-th Node
    temp1->next = temp2->next; // (n+1)-th node
    free(temp2); //deallocate the memory
}

int LinkList6(void)
{
    head=NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); //List: 2,4,6,5
    Print();
    int n;
    printf("Enter a position:\n");
    scanf("%d",&n);
    Delete(n);
    Print();
    
    return 0;
}





