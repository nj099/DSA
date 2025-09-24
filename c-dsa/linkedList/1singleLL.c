#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

  void insertAtStart(int value,struct Node** head){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
   
      newNode->data=value;
      newNode->next=*head;
      *head=newNode;
  }

  void insertAtTail(int value,struct Node** head){
    struct Node*temp=*head;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) { // Check if memory allocation was successful
        printf("Memory allocation failed\n");
        return;
    }
    if(*head==NULL){
      newNode->data=value;
      *head=newNode;
      newNode->next=NULL;
      return;


    }
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=NULL;
    newNode->data=value;
  }


  void display(struct Node*head){

    struct Node *temp=head;

    while(temp!=NULL){
      printf("%d -> ",temp->data);
      temp=temp->next;
    }

  }



int main() {

  struct Node* head=NULL;

  insertAtStart(4,&head);
  insertAtStart(5,&head);
  insertAtTail(9,&head);
  display(head);
  
  return 0;
}