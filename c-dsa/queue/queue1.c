#include<stdio.h>
#include<stdlib.h>

struct queue{
int size;
int f;
int r;
int *ptr;
};

void initilize(struct queue *q,int size){
    (*q).size=size;
    q->f=q->r=-1;
    q->ptr=(int*)malloc(q->size*sizeof(int));
}

void enqueue(struct queue *q,int val){
    if(q->r==q->size-1){
        printf("queue is full");
        return;
    }
    q->r++;
    q->ptr[q->r]=val;
    printf("Enqueued: %d\n", val);
}

int dequeue(struct queue *q){
    if (q->f == q->r)
    {
        printf("queue is empty");
        return 1;
    }
    
q->f++;
int val = q->ptr[q->f];
printf("Dequeued: %d\n", val);
return val;

}

int main() {
    struct queue q;
    initilize(&q,40);
    enqueue(&q,5);
    enqueue(&q,8);
    enqueue(&q,1);
    dequeue(&q);

    return 0;
}