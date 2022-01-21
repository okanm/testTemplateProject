//REVERSE A LINK LIST (Iterative Approach)
//Two approaches: 1- Iterative approach (u use loop; traverse the list and revert one of the links at each step) (we do this here), 2- Recursion 
//(head local variable)
#include "common.h"

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

static struct Node* Insert(struct Node *head, int data)
{
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

static void Print(struct Node *head)
{
    printf("List is: ");
    while (head!=NULL){
        printf("%d ", head->data);
        head=head->next;
    }
    printf("\n");
}

static struct Node* Reverse(struct Node* head){
    struct Node *current,*prev,*next; //you need to know previous adress 
    //(you know next adress but not previous adress in L-List)
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev; //you need to update head (it is now start at end of the list)
    return head;
}

int LinkList7(void)
{
    struct Node *head=NULL; // local variable
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    Print(head);
    head=Reverse(head);
    Print(head);
    
    return 0;
}

/*
Note:
The reverse function template:

void Reverse(){
    struct Node *current,*prev,*next; //you need to know previous adress (you know next adress but not previous adress in L-List). Current always points to current, prev stores prev node address, next stores next node address
    current=head;
    prev=NULL;
    while( current!=NULL)
    {
        next=current->next; // next stores the adress of next node
        current->next=prev; //prev is always the node behind
        prev=current; //
        current=next;
    }
    head=prev; //you need to update head (it is now start at end of the list)
}
*/



