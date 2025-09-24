#include <stdio.h>



void mergeSort(int arr[],int si,int ei)
{
    int n=5;
    int mid=si + (ei-si)/2;
    if (si==ei){
         return;
    }
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);

    //concure
    int temp[ei-si+1];
    int i = si;      // Pointer for left half
    int j = mid + 1; // Pointer for right half
    int k = 0;       // Pointer for temp array
    while(i<=mid && j<=ei){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++,k++;
        }
        else{
            temp[k]=arr[j];
            j++,k++;
        }
    }
    // Copy remaining elements from left half, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right half, if any
    while (j <= ei) {
        temp[k++] = arr[j++];
    }
    // Copy merged elements back to original array
    for (int x = 0; x < k; x++) {
        arr[si + x] = temp[x];
    }
    
}

int main()
{
    int arr[5] = {1, 8, 4, 6, 3};
    int n=5;
    mergeSort(arr,0,n-1);
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d",arr[i]);
    }

    return 0;
}
//array's are always pass by reference 