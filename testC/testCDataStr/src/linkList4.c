//INSERT NODE AT THE END (head global variable)
#include "common.h"

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

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

int LinkList4(void)
{
    head=NULL;
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        printf("Enter the number:\n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
    
    return 0;
}
