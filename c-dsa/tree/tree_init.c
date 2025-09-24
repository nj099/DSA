#include<stdio.h>
#include<stdlib.h>
struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
};

struct TreeNode* create(int val){
    struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data=val;
    root->left=root->right=NULL;
    root->height=1;
    return root;
}


int main(){
    struct TreeNode* root =NULL;
    root=create(6);
    printf("%d",root->data);
    return 0;
}