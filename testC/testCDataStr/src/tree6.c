//Check if a binary tree is binary search tree or not Approach 1
//This approach is not so good, because lots of recursion. In other words, you compare each node with each node in left/right subtree
#include "common.h"

struct BstNode{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

static int IsSubtreeLesser(struct BstNode* root, int value){
    if(root==NULL) return true;
    if(root->data <= value
        && IsSubtreeLesser(root->left, value)
        && IsSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}

static bool IsSubtreeGreater(struct BstNode* root, int value){
    if(root==NULL) return true;
    if(root->data > value
        && IsSubtreeGreater(root->left, value)
        && IsSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}

static bool IsBinarySearchTree(struct BstNode* root){
    if(root==NULL) return true;
    if(IsSubtreeLesser(root->left,root->data)
        && IsSubtreeGreater(root->right,root->data)
        && IsBinarySearchTree (root->left)
        && IsBinarySearchTree(root->right))
        return true;
    else
        return false;

}
struct BstNode* GetNewNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data=data; //(*newNode).data=data;
    newNode->left=newNode->right=NULL;
    return newNode; //returns address
}

struct BstNode* Insert(struct BstNode* root, int data){
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

int Tree6(void)
{
    struct BstNode* root=NULL;
    root=Insert(root, 15);
    root=Insert(root, 10);
    root=Insert(root, 20);
    root=Insert(root, 25);
    root=Insert(root, 8);
    root=Insert(root, 12);
    if(IsBinarySearchTree(root)==true)
        printf("This is a Binary Search Tree\n");
    else
        printf("This is NOT a Binary Search Tree!\n");
    return 0;
}

/*
Note: you can also write FindMax and FindMin for subtrees instead of IsSubtreeGreater and IsSubtreeLesser.
*/