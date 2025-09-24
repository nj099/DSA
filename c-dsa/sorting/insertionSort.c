// [5, 3, 4, 1]
// Step 1: Compare 3 with 5 → insert 3 before 5 → [3, 5, 4, 1]
// Step 2: Compare 4 with 5 → insert 4 before 5 → [3, 4, 5, 1]
// Step 3: Compare 1 with 5, 4, 3 → insert 1 at beginning → [1, 3, 4, 5]

//pehle shift karo


#include <stdio.h>

void insertionSort(int arr[])
{   
    int n=5;

    for (int i = 1; i < n; i++)
    {   int j=i-1,key=arr[i];
        while (j>=0 &&arr[j]>key)
        {
             arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    





    for (int i = 0; i < 5; i++)
    {
        printf("%d",arr[i]);
    }
    
}

int main()
{
    int arr[5] = {1, 8, 4, 6, 3};
    insertionSort(arr);

    return 0;
}