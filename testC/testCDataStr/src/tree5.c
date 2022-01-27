//Binary tree traversal: Preorder, Inorder, Postorder
#include "common.h"

struct BstNode{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

static void Preorder(struct BstNode* root){
    if (root==NULL) return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

static void Inorder(struct BstNode* root){
    if (root==NULL) return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

static void Postorder(struct BstNode* root){
    if (root==NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
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

int Tree5(void)
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
    //1 for Preorder, 2 for Inorder, 3 for Postorder
    printf("Enter a number to choose traversal algorithm\n");
    printf("1 for Preorder, 2 for Inorder, 3 for Postorder):\n");
    int choose;
    scanf("%d",&choose);
    switch(choose){
        case 1:
            Preorder(root);
            break;
        case 2:
            Inorder(root);
            break;
        case 3:
            Postorder(root);
            break;
        default:
            printf("Choose between 1,2 or 3\n");
    }       

    return 0;
}
