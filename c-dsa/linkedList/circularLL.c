#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

  void insertAtStart(int value,struct Node** head){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
   
      newNode->data=value;
      if (*head == NULL) {
        newNode->next = newNode; // Point to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        // Move to last node to update its next pointer
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode; // New node becomes head
    }
  }

  void insertAtTail(int value,struct Node** head){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode; // Point to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        // Move to last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; // Point back to head
    }
  }


  void display(struct Node*head){

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
  }



int main() {

  struct Node* head=NULL;

  insertAtStart(4,&head);
  insertAtStart(5,&head);
  insertAtTail(9,&head);
  display(head);
  
  return 0;
}