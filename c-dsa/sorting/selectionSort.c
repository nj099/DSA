#include <stdio.h>

void selectionSort(int arr[])
{
    for (int i = 0; i < 4; i++)
    {   int mindex=i;
        for (int  j = i+1; j <5 ; j++)
        {
            if(arr[j]<arr[mindex]){
                mindex=j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[mindex];
        arr[mindex] = temp;
    }
    


    for (int i = 0; i < 5; i++)
    {
        printf("%d",arr[i]);
    }
    
}

int main()
{
    int arr[5] = {1, 8, 4, 6, 3};
    selectionSort(arr);

    return 0;
}