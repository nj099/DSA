#include <stdio.h>

void bubbleSort(int arr[])
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4-i; j++)
        {
            if (arr[j] >arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d",arr[i]);
    }
    
}

int main()
{
    int arr[5] = {1, 8, 4, 6, 3};
    bubbleSort(arr);

    return 0;
}