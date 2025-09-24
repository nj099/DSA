#include<stdio.h>
#include<stdlib.h>
struct Array{
  int maxSize;
  int top;
  int *ptr;
};

void createstackArray(struct Array *arr,int size){
  arr->maxSize = size;
  arr->ptr = (int*)malloc(arr->maxSize*sizeof(int));
  arr->top=-1;
}

void push(struct Array *arr,int val){
  if (arr->top == arr->maxSize-1) {
        printf("Stack Overflow!\n");
        return;
    }
  arr->top++;
  arr->ptr[arr->top]=val;
  printf("%d pushed to stack.\n", val);
}

int  pop(struct Array *arr){
  if (arr->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int val=(*arr).ptr[arr->top];
    arr->top--;
  return val ;
}

int peek(struct Array *arr) {
    if (arr->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return arr->ptr[arr->top];
}

int isEmpty(struct Array *arr) {
    return arr->top == -1;
}

int isFull(struct Array *arr) {
    return arr->top == arr->maxSize - 1;
}


void show(struct Array arr) {
    if (arr.top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elementarr : ");
    for (int i = arr.top; i >= 0; i--) {
        printf("%d ", arr.ptr[i]);
    }
    printf("\n");

}


int main() {
  struct Array stackArray;
  createstackArray(&stackArray,30);
  push(&stackArray,9);
  push(&stackArray,6);
  push(&stackArray,5);
  pop(&stackArray);
  show(stackArray);


  return 0;
}