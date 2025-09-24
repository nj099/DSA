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

int height(struct TreeNode* node){
    if(node==NULL) return 0;
    return node->height;
}
int max(int a,int b){
    return (a > b) ? a : b;
}

int getbalance(struct TreeNode* node){
    return height(node->left) - height(node->right);
}

struct TreeNode* rightRotation(struct TreeNode* x){
   struct TreeNode* y=x->left;
   struct TreeNode* t2=y->right;

   y->right=x;
   x->left=t2;

   x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
   return y;//new root
}
struct TreeNode* leftRotation(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* t2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = t2;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y; // ✅ y is the new root after left rotation
}
struct TreeNode* insert(struct TreeNode* newNode,int val){

    if(newNode==NULL) return create(val);

    if(val<newNode->data){
        newNode->left = insert(newNode->left,val);
    }
    else{
        newNode->right = insert(newNode->right,val);
    }

    //update height
    newNode->height=1+max(height(newNode->left),height(newNode->right));

    int balance= getbalance(newNode);//newnode-> rootNode

    // LL Case
    if(balance>1 && val<newNode->left->data){
        return rightRotation(newNode);
    }
    // LR Case
    if(balance>1 && val>newNode->left->data){
        newNode->left=leftRotation(newNode->left);
        return rightRotation(newNode);
    }
    // RR Case
    if(balance<-1 && val>newNode->right->data){
        return leftRotation(newNode);
    }
    // RL Case
    if(balance<-1 && val<newNode->right->data){
        newNode->right=rightRotation(newNode->right);
        return leftRotation(newNode);
    }





    return newNode;//here if not rotation then always retun root org
}
void preorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct TreeNode* root =NULL;
    root = insert(root,7);
    root = insert(root,5);
    root = insert(root,3);
    root = insert(root,9);
    root = insert(root,4);
    root = insert(root,8);
    printf("%d ",root->height);
    printf("%d ",root->right->height);
    printf("%d\n",getbalance(root));
    preorder(root);

    return 0;
}