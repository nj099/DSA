#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};
  struct Node *top = NULL;

void push(int val){
  struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
  new_node->data=val;
  new_node->next=top;//now its right not NULL
  top=new_node;
}

void show(){
//now i can use top coz it is a global var any changes would be permanent  
  struct Node *temp = top;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  push(10);
  push(20);
  push(30);
  show();

  return 0;
}

//Because top is global, any change you make to it inside push is permanent and visible everywhere in your program. So, even though you’re not using call-by-reference explicitly, the changes to top are permanent because you’re directly modifying a global pointer.

