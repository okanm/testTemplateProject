// Delete a node from Binary Search Tree
#include "common.h"

struct BstNode{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

static struct BstNode* FindMin(struct BstNode* root){
    if(root==NULL){
        printf("Tree is empty\n");
        return root;
    }
    struct BstNode* current=root;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}

static struct BstNode* Delete(struct BstNode* root, int data){
    if (root==NULL) return root;
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else {
        //Case 1: no child
        if (root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        //Case 2: one child
        else if (root->left==NULL){
            struct BstNode* temp=root;
            root=root->right;
            free(temp);
        }
        else if (root->right==NULL){
            struct BstNode* temp=root;
            root=root->left;
            free(temp);
        }   
        //Case 2: two children
        else{
            struct BstNode* temp=FindMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root; 
}
static void Inorder(struct BstNode* root){
    if (root==NULL) return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
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

int Tree8(void)
{
    struct BstNode* root=NULL;
    root=Insert(root, 12);
    root=Insert(root, 5);
    root=Insert(root, 15);
    root=Insert(root, 3);
    root=Insert(root, 7);
    root=Insert(root, 13);
    root=Insert(root, 17);
    root=Insert(root, 1);
    root=Insert(root, 9);
    printf("Before Deletion:\n");
    Inorder(root);
    Delete(root,15);
    printf("\n");
    printf("After Deletion:\n");
    Inorder(root);
    return 0;
}
