//Binary tree: Level Order Traversal
#include "common.h"

struct BstNode{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct QueueNode* front=NULL;
struct QueueNode* rear=NULL;

struct QueueNode{
    long long data;
    struct QueueNode *next;
};

struct QueueFncs{
    void (*fp_enq)(void* x);
    void (*fp_deq)();
    bool (*fp_empty)();
    long (*fp_front)();
};

static void Enqueue(void* x){
    struct QueueNode* temp=(struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->data=(long long)x;
    temp->next=NULL;
    //if queue is empty
    if (front==NULL && rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
static void Dequeue(){
    struct QueueNode* temp=front;
    //if list is empty
    if (front==NULL){
        printf("Queue is Empty\n");
        return;
    }
    if (front==rear){
        front = rear = NULL;
    }
    else{
        front=front->next;
    }
    free(temp);
}

static long Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return -1;
	}
	return front->data;
}

static bool isEmpty(){
    if (front==NULL && rear==NULL){
        return true;
    }
    else{
        return false;
    }
}
static void LevelOrder(struct BstNode* root){
    if(root==NULL) return;
    struct QueueFncs Q;
    Q.fp_enq=&Enqueue;
    Q.fp_deq=&Dequeue;
    Q.fp_empty=&isEmpty;
    Q.fp_front=&Front;
    
    (*(Q.fp_enq))(root);
    //While there is at least one discover node
    while(!(*(Q.fp_empty))()){
        struct BstNode* current=(struct BstNode*)(*(Q.fp_front))();
        printf(">>>> %p - %d\n", &current->data, current->data);
        if(current->left!=NULL) (*(Q.fp_enq))(current->left);
        if(current->right!=NULL) (*(Q.fp_enq))(current->right);
        (*(Q.fp_deq))(); //removing the element at front
    }
}

static struct BstNode* GetNewNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data=data; //(*newNode).data=data;
    newNode->left=newNode->right=NULL;
    return newNode; //returns address
}

static bool Search(struct BstNode* root, int data){
    if (root==NULL) return false; // tree is empty
    else if(root->data==data) return true;
    else if(data<=root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

static struct BstNode* Insert(struct BstNode* root, int data){
    if (root==NULL){ // tree is empty
        root=GetNewNode(data);
    }
    else if(data<=root->data){
        root->left=Insert(root->left,data);
    }
    else{
        root->right=Insert(root->right,data);
    }
    return root; //return the adress
}

int Tree4(void)
{
    struct BstNode* root=NULL;
    root=Insert(root, 15);
    root=Insert(root, 10);
    root=Insert(root, 20);
    root=Insert(root, 25);
    root=Insert(root, 8);
    root=Insert(root, 12);
    //int number;
    //printf("Enter a number to be searched:\n");
    //scanf("%d",&number);
    //if (Search(root,number)==true) printf("Found\n");
    //else printf("Not Found\n");
    LevelOrder(root);
    
    return 0;
}
