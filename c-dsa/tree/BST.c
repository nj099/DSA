#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};



void insert(struct TreeNode**root,int val){

    if((*root)==NULL){
        struct TreeNode* newNode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data=val;
        newNode->left = newNode->right=  NULL;
        *root=newNode;
        return;
    }

    if(val<(*root)->data){
        insert(&((*root)->left),val);
        return;
    }
    else{
        insert(&((*root)->right),val);
        return;

    }
}

void inorder(struct TreeNode* root){
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void delete(struct TreeNode** root,int target){

    if(target<(*root)->data){
        delete(&((*root)->left),target);
    }
    else if(target>(*root)->data){
        delete(&((*root)->right),target);
    }
    else if(target==(*root)->data){
        struct TreeNode* temp = *root;     
        //case 1 no child
        if((*root)->left==NULL && (*root)->right==NULL){ //*root=*root->left //⁡⁢⁢⁢root is not node3(target) its root5(org root) ka left⁡ 
            free(*root); 
            *root=NULL;
        }
        //1 child
        else if(!((*root)->left==NULL) && (*root)->right==NULL){
            (*root)=(*root)->left;
            free(temp);
        }
        else if((*root)->left==NULL && !((*root)->right==NULL)){
            *root = (*root)->right;
            free(temp);
        }
        //2child
        else{
            
            struct TreeNode* succ = (*root)->right;
            while (succ->left != NULL) succ = succ->left;
            (*root)->data = succ->data;
            delete(&((*root)->right), succ->data);
        }
    }


}


int main(){
    int arr[] = {5, 7, 4, 8, 3, 2, 9,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct TreeNode* root = NULL;
    for (int i = 0; i < n; i++){
        insert(&root, arr[i]);
    }

    printf("Inorder Traversal of BST: ");
    inorder(root);
    printf("\n");

    delete(&root,3);
    inorder(root);

    return 0;
}
