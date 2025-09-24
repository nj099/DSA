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
    return 0;
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
    return 0;
}

void sort(struct myArray *arr) {
    for (int i = 0; i < arr->used_size - 1; i++) {
        for (int j = i + 1; j < arr->used_size; j++) {
            if (arr->ptr[i] > arr->ptr[j]) {
                int temp = arr->ptr[i];
                arr->ptr[i] = arr->ptr[j];
                arr->ptr[j] = temp;
            }
        }
    }
}

void search(struct myArray *arr, int val)
{
   // Create a copy
    int *copy = (int *)malloc(arr->used_size * sizeof(int));
    for (int i = 0; i < arr->used_size; i++) {
        copy[i] = arr->ptr[i];
    }

    // Sort the copy
    for (int i = 0; i < arr->used_size - 1; i++) {
        for (int j = i + 1; j < arr->used_size; j++) {
            if (copy[i] > copy[j]) {
                int temp = copy[i];
                copy[i] = copy[j];
                copy[j] = temp;
            }
        }
    }

    // Binary search on copy
    int low = 0;
    int high = arr->used_size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (copy[mid] == val) {
            printf("value %d found (sorted index %d)\n", val, mid);
            free(copy);
            return;
        }
        else if (copy[mid] < val) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("value %d not found\n", val);
    free(copy);

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
    showValue(marks);

    return 0;
}