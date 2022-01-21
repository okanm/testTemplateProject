// INSERT NODE AT THE BEGINNING (head global variable)
#include "common.h"

//no need to add these function declaration because your functions are static. i.e nothing else will use these
//static void Insert(int x);
//static void Print();

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

/*void Insert(int x) // original
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if (head != NULL) temp->next=head;
    head=temp;
}*/

static void Insert(int x) // better
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

static void Print()
{
    struct Node *temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int LinkList1(void)
{

    head = NULL;
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number:\n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }

    return 0;
}

/* End of this file*/
