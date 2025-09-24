#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* create(){
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d",&x);

    if(x==-1){
        return NULL;
    }

    // Allocate memory for a new node
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = x;

    printf("Enter left child of %d:\n", x);
    newNode->left=create();//it is returning a treeNode(a new newNode) and we store it in prev newNode -> left
    printf("Enter right child of %d:\n", x);
    newNode->right=create();

    return newNode;
}

void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct TreeNode* root=NULL;
    printf("Create the binary tree:\n");
    root=create();

    preorder(root);


    return 0;
}