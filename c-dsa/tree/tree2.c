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
            return;
        }
        else{
            //enque in queue
            struct QNode* new=(struct QNode*)malloc(sizeof(struct QNode));
            q.rear->next=new;
            new->addTreeNode=current->left;
            new->next=NULL;
            q.rear=new;
        }

        if (current->right == NULL) {
            current->right = newNode;
            return;
        } else {
            struct QNode* rightNode = (struct QNode*)malloc(sizeof(struct QNode));
            rightNode->addTreeNode = current->right;
            rightNode->next = NULL;
            q.rear->next = rightNode;
            q.rear = rightNode;
        }
    }
}


void levelOrder(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Queue q;
    initQueue(&q);

    // Create and enqueue the root node
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->addTreeNode = root;
    temp->next = NULL;
    q.front = q.rear = temp;

    while (q.front != NULL) {
        // Dequeue the front node
        struct QNode* frontNode = q.front;
        struct TreeNode* current = frontNode->addTreeNode;

        // Print the current tree node's data
        printf("%d ", current->data);

        // Move front to next and free the dequeued node
        q.front = q.front->next;
        if (q.front == NULL)
            q.rear = NULL; // Important: reset rear if queue becomes empty
        free(frontNode);

        // Enqueue left child if it exists
        if (current->left) {
            struct QNode* left = (struct QNode*)malloc(sizeof(struct QNode));
            left->addTreeNode = current->left;
            left->next = NULL;
            if (q.rear == NULL)
                q.front = q.rear = left;
            else {
                q.rear->next = left;
                q.rear = left;
            }
        }

        // Enqueue right child if it exists
        if (current->right) {
            struct QNode* right = (struct QNode*)malloc(sizeof(struct QNode));
            right->addTreeNode = current->right;
            right->next = NULL;
            if (q.rear == NULL)
                q.front = q.rear = right;
            else {
                q.rear->next = right;
                q.rear = right;
            }
        }
    }
}


void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}



int main(){

    struct TreeNode*root=NULL;

    insert(&root,1);
    insert(&root,2);
    insert(&root,3);

    levelOrder(root);
    printf("\n");
    preorder(root);
    printf("\n");


    return 0;
}