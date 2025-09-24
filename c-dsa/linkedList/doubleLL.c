#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int insertAtStart(int val,struct Node **head){
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=val;
    (*new_node).next=*head;
    (*new_node).prev=NULL;
      if (*head != NULL) {
        (*head)->prev = new_node;  // Important: update previous head's prev
    }

    (*head)=new_node;
    return 0;
}

void show(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d - ",(*temp).data);
        temp=temp->next;
    }
}

int main(){
    struct Node *head=NULL;

    insertAtStart(6,&head);
    insertAtStart(45,&head);
    show(head);


    return 0;
}