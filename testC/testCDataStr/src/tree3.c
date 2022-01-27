//Find min and max element in a binary search tree (Loop solution) & find the height
// You can find min max in two ways: 1- loop 2- recursion
// To find min(max), you have to go left(right) as much as possible, because it is BST, min(max) values are always on the left(right)
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

static int FindMin(struct BstNode* root){
    if(root==NULL){
        printf("Tree is empty\n");
        return -1;
    }
    else if(root->left==NULL){
        return root->data;
    }
    return FindMin(root->left);
}
static int FindMax(struct BstNode* root){
    if(root==NULL){
        printf("Tree is empty\n");
        return -1;
    }
    else if(root->right==NULL){
        return root->data;
    }
    return FindMax(root->right);
}

static int FindHeight(struct BstNode* root){
    if(root==NULL) return -1;
    return max(FindHeight(root->left),FindHeight(root->right))+1;
}

int Tree3(void)
{
    struct BstNode* root=NULL;
    root=Insert(root, 15);
    root=Insert(root, 10);
    root=Insert(root, 20);
    root=Insert(root, 25);
    root=Insert(root, 8);
    root=Insert(root, 12);
    printf("Min: %d\n",FindMin(root));
    printf("Max: %d\n",FindMax(root));
    printf("Height: %d\n",FindHeight(root));
    
    return 0;
}