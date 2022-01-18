//INSERT NODE AT THE BEGINNING v2-1 (head local variable)
//Here, you need to give arguments to the functions

#include "common.h"

struct Node{
    int data;
    struct Node *next;
};

struct Node* Insert(struct Node *head, int x) // we have to update head, so we return struct here instead of void
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
    return head;
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

int test2(void)
{
    struct Node *head=NULL;
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        printf("Enter the number:\n");
        scanf("%d", &x);
        head = Insert(head, x); // we have to update head, so we return a (updated) value 
        Print(head);
    }
    

    return 0;
}
