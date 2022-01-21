//ARRAY IMPEMENTATION OF STACK
//In array, when u pop, u don’t need to delete the element from the array. You will overwrite it anyways if necessary
//If overflow, create a larger array (e.g.twice the smaller), copy all the elements
#include "common.h"
#define MAX_SIZE 101


//Global variables
int A[MAX_SIZE];
static int top=-1;

static void Push(int x){
    if (top==MAX_SIZE-1){
        printf("Error: Stack overflow\n");
        return;
    }
    top=top+1; //or top++;
    A[top]=x; 
    //these two lined can be written as A[++top]=x
}

static void Pop(){
    if (top==MAX_SIZE-1){
        printf("Error: No element to pop\n");
        return;
    }
    top--;
}

/*
static int Top(){
    return A[top];
}
*/

/*
? isEmpty(){
    if (top==1){
        return true;
    }else{
        return false;
    }
}*/

static void Print(){
    int i=0;
    printf("Stack: ");
    for(i=0; i<=top; i++)
        printf("%d ",A[i]);
    printf("\n");
}

int Stack1(void){
    
    Push(2); Print();
    Push(5); Print();
    Push(10); Print();
    Pop(); Print();
    Push(12); Print();

    return 0;
}
