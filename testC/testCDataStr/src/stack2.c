//LINKED LIST IMPEMENTATION OF STACK
// Stack means insert&delete at one end. So, you have two options; insert&delete 1- At end of list (tail) or 2- At the beginning of list (head)
// But options 1 is O(n), i.e. you travererse n element to insert&delete, so option 2 is better because it is O(1).
#include "common.h"

struct Node {
    int data;
    struct Node* link;
};

static struct Node* top=NULL; //use top instead of head in stack

static void Push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->link=top;
    top=temp;
}

static void Pop(){
    struct Node* temp;
    if (top==NULL) return;
    temp=top;
    top=top->link;
    free(temp);
}

static void Print()
{
    struct Node* temp = top;
    printf("Stack: ");
    while (temp!=NULL){
        printf(" %d", temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int Stack2(void){
    
    Push(2); Print();
    Push(5); Print();
    Push(10); Print();
    Pop(); Print();
    Push(12); Print();

    return 0;
}
