#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

void insert(struct TreeNode** root,int data){

if((*root)==NULL){
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    (*root)=newNode;
    return;
}

if(data<(*root)->data){
    insert(&(*root)->left,data);
}
else{
    insert(&(*root)->right,data);
}

}

void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(struct TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    struct TreeNode* root=NULL;
    printf("Create the binary tree:\n");
    insert(&root,4);
    insert(&root,3);
    insert(&root,5);
    insert(&root,1);
    insert(&root,9);

    preorder(root);

    return 0;
}