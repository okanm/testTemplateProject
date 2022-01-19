//INSERT NODE AT THE BEGINNING v2-2 (head local variable)
//Here, you need to give arguments to the functions

#include "common.h"

struct Node{
    int data;
    struct Node *next;
};

// you pass this now because you give address in the main function
static void Insert(struct Node **ptrHead, int x) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=*ptrHead;
    *ptrHead=temp;
    }

static void Print(struct Node *head) //this 'head' is local variable actually, so we can traverse it.
{
    printf("List is: ");
    while (head!=NULL){
        printf(" %d", head->data);
        head=head->next;
    }
    printf("\n");
}

int test3(void)
{
    struct Node *head=NULL;
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        printf("Enter the number:\n");
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }
    
    return 0;
}
