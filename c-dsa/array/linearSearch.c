#include <stdio.h>
#include <stdlib.h>
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *arr, int tSize, int uSize)
{
    arr->total_size = tSize; // same as (*arr).totalsize=tSize  *value atopr
    arr->used_size = uSize;
    arr->ptr = (int *)malloc(tSize * sizeof(int));
}

void setValue(struct myArray *arr)
{
    printf("enter values:\n");
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("arr[%d] ", i);
        scanf("%d", &(*arr).ptr[i]);
    }
}

void showValue(struct myArray arr)
{
    for (int i = 0; i < arr.used_size; i++)
    {
        printf("arr[%d]= %d   ", i, arr.ptr[i]);
    }
    printf("\n");
}

int insertAtIndex(struct myArray *arr, int idx, int val)
{
    if (arr->used_size >= arr->total_size)
    {
        return -1;
    }
    if (idx > arr->used_size)
    {
        return -1;
    }

    for (int i = arr->used_size; i >= idx; i--)
    {
        arr->ptr[i + 1] = arr->ptr[i];
    }
    arr->ptr[idx] = val;

    arr->used_size++;
}

int deleteAtIndex(struct myArray *arr, int idx)
{
    if (idx < 0 || idx >= arr->used_size)
    {
        printf("Invalid index for deletion!\n");
        return -1;
    }

    for (int i = idx + 1; i < arr->used_size; i++)
    {
        arr->ptr[i - 1] = arr->ptr[i];
    }
    arr->used_size--;
}

void search(struct myArray *arr, int val)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        if (arr->ptr[i] == val)
        {
            printf("value is at index %d ", i);
            return;
        }
    }
     printf("Value does not exist\n");
}

void freeArray(struct myArray *arr)
{
    free(arr->ptr);
    arr->ptr = NULL; // Avoid dangling pointer
}

int main()
{
    struct myArray marks;
    createArray(&marks, 30, 5);
    setValue(&marks);
    showValue(marks);
    insertAtIndex(&marks, 3, 9);
    showValue(marks);
    deleteAtIndex(&marks, 5);
    showValue(marks);

    search(&marks, 8);

    return 0;
}

// marks is a  structure variable of type struct myArray Inside it, there is a pointer to an array. so when i want to access then arr (marks) me ptr->[i]
// write now our free is public so we can use it main but if we do static then we have to use fun