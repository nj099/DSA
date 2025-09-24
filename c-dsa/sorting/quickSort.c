#include <stdio.h>

int partition(int arr[],int si,int ei){

    int i=si,j=si;
    int pivit=arr[ei];

    while(i<=ei){
        if(arr[i]<=pivit){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++,j++;
        }
        else{
            i++;
        }
    }
    return j-1;

}

void quickSort(int arr[],int si,int ei)
{

    if(si>=ei){//if pivit=0 then pivit-1=-1 so si>ei
        return;
    }
    int pivit=partition(arr,si,ei);
    quickSort(arr,si,pivit-1);
    quickSort(arr,pivit+1,ei);

}

int main()
{
    int arr[8] = {1, 8, 4, 6, 3};
    int n=5;
    quickSort(arr,0,n-1);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}