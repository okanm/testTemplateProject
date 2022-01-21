//INSERT NODE AT THE N-TH POSITION (head global variable)
// you want to insert node on the n-th position, so u need to go to (n-1)-th position
//you have to consider special cases like if the list is empty or position is out of range
// If head is not global, then we do what we did previously: 1- in each call, we return some values from the function to update the head or 2- we pass the head by reference
#include "common.h"

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

// you need another argument; the position of the new node.
static void Insert(int x, int n) 
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data=x;
    temp1->next=NULL;
    if (n==1) {
        temp1->next=head;
        head=temp1;
        return; // you can return here, temp1 is the newly created node
    }
    struct Node* temp2=head; //temp2 is to find the position
    for (int i=0; i<n-2; i++){
        temp2=temp2->next;
    } // loop until n-1
    temp1->next = temp2->next; 
    temp2->next = temp1;
}

static void Print()
{
    struct Node* temp=head;
    printf("List is: ");
    while (temp!=NULL){
        printf(" %d", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int LinkList5(void){
    
    head=NULL;
    Insert(2,1); //List: 2
    Insert(3,2); //List: 2,3
    Insert(4,1); //List: 4,2,3
    Insert(5,2); //List: 4,5,2,3
    Print();

    return 0;
}
