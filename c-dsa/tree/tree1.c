// tree using queue for level wise insert and using linked list impplwment of queue
//here queue stores address of treeNode insead  of int data
//we use struct Queue q in insert not in main 

#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct QNode{
    struct TreeNode* addTreeNode;
    struct QNode* next;
};
struct Queue{
    struct QNode* front;
    struct QNode* rear;
};

void initQueue(struct Queue*q){
    q->front=q->rear=NULL;
}
//root store add of maain root so *root is value at add=main root
void insert(struct TreeNode** root,int val){//here root is ptr to ptr 
    struct TreeNode* newNode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    (*newNode).data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    
    if((*root)==NULL){
        *root=newNode;
        return;
    }

    struct Queue q;
    initQueue(&q);
    struct QNode* new_node=(struct QNode*)malloc(sizeof(struct QNode));
    new_node->addTreeNode=(*root);//newnode store add of root
    new_node->next=NULL;
    q.rear=new_node;
    q.front=new_node;

    while(q.front!=NULL){
        struct QNode* temp=q.front;
        struct TreeNode* current=temp->addTreeNode;
        q.front=q.front->next;
        free(temp);

        if(current->left==NULL){
            current->left=newNode;
            break;
        }
        else{
            //enque in queue
            struct QNode* new=(struct QNode*)malloc(sizeof(struct QNode));
            q.rear->next=new;
            new->addTreeNode=current->left;
            new->next=NULL;
            q.rear=q.rear->next;
        }

        if (current->right == NULL) {
            current->right = newNode;
            break;
        } else {
            struct QNode* rightNode = (struct QNode*)malloc(sizeof(struct QNode));
            rightNode->addTreeNode = current->right;
            rightNode->next = NULL;
            q.rear->next = rightNode;
            q.rear = rightNode;
        }
    }
}




int main(){

    struct TreeNode*root=NULL;

    insert(&root,1);
    insert(&root,2);
    insert(&root,3);
    insert(&root,4);
    insert(&root,5);




    return 0;
}

// Is left child empty? ✅ Insert here.
// Else, enqueue the left child (to check its children later)
// Is right child empty? ✅ Insert here.
// Else, enqueue the right child.