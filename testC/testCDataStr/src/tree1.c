//BST IMPLEMENTATION 
//Here, define root as local variable
//After creating root, use recursion to add other nodes (to left or to right), because recursion is used often in trees
#include "common.h"

struct BstNode{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

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

int Tree1(void)
{
    struct BstNode* root=NULL;
    root=Insert(root, 15);
    root=Insert(root, 10);
    root=Insert(root, 20);
    root=Insert(root, 25);
    root=Insert(root, 8);
    root=Insert(root, 12);
    int number;
    printf("Enter a number to be searched:\n");
    scanf("%d",&number);
    if (Search(root,number)==true) printf("Found\n");
    else printf("Not Found\n");
    
    return 0;
}

//Remember, you can also do it like this:
/*
void Insert(struct BstNode** rootptr, int data);
    if (*rootptr==NULL){ // if tree is empty
        *rootptr=GetNewNode(data);
    }


int main()
{
    struct Node* root=NULL;
    root=Insert(&root, 15);
    root=Insert(&root, 10);
    root=Insert(&root, 20);
    
    return 0;
}
*/
