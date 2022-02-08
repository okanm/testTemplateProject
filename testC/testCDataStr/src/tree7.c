//Check if a binary tree is binary search tree or not Approach 2
//More efficient way: define a range for each node
#include "common.h"

struct BstNode{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

static bool IsBstUtil(struct BstNode* root, int minValue,int maxValue){
    if(root==NULL) return true;
    if(root->data > minValue
        && root->data < maxValue
        && IsBstUtil(root->left, minValue, root->data)
        && IsBstUtil(root->right, root->data, maxValue))
        return true;
    else
        return false;
}

static bool IsBinarySearchTree(struct BstNode* root){
    return IsBstUtil(root, (int)INT_MIN, (int)INT_MAX);
//make INF to integer, because it is float in math.h
}

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

int Tree7(void)
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
Note: Approach 3
You can also use in-order Traversal and check the result. If it is sorted, it is BST.
*/