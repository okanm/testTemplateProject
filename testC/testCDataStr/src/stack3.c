//REVERSE A STRING USING STACK (Linked List implementation)
//idea is, first put the characters to stack from left to right, then from top get them again
#include "common.h"

struct Node {
    char data;
    struct Node* link;
};

struct Node* top=NULL;

static void Push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->link=top;
    top=temp;
}

static void Pop(){
    struct Node* temp=top;
    if (top==NULL) return;
    temp=top;
    top=top->link;
    free(temp);
}

static char Top(){
    return top->data;
}

// we use stack here
static void Reverse(char C[], int n) //char C[] or char* C
{
    //loop for push
    for (int i=0; i<n; i++){
        Push(C[i]);
    }
    //loop for Pop
    for (int i=0; i<n; i++){
        C[i]=Top(); // overwrite the character at index i
        Pop(); // perform pop
    }
}

int Stack3(void){
    char C[51];
    printf("Enter a string:\n");
    scanf("%s", C);
    //printf("%s",C);
    Reverse(C,strlen(C));
    //printf("%lu\n",strlen(C));
    printf("Output = %s\n",C);

    return 0;
}
