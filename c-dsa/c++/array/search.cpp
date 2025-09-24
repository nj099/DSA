#include<iostream>

// class Solution{
//     public:
//     int search(int arr[],int n,int target){
//         for (int i = 0; i < n; i++)
//         {
//             if(arr[i]==target)
//             return i;
//         }
//         return -1;
//     }
// };

// int main(){
//     int arr[]={7,8,3,6,45,8};
//     int size=sizeof(arr)/sizeof(arr[0]);
//     int target=8;
//     Solution sol;
//     int result=sol.search(arr,size,target);
//     std::cout<<result;


//     return 0;
// }

// int ⁡⁣⁣⁡⁢⁢⁣arr[] and int* arr are the same⁡ in function parameters

class Solution{
    public:
    int search(int *arr,int n,int target){
        for (int i = 0; i < n; i++)
        {
            if(*(arr+i) ==target)
            return i;
        }
        return -1;
    }
};

int main(){
    int *arr;
    int size=5;
    arr=new int[size];
    std::cout<<"enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        // std::cin>>*(arr + i);
        std::cin>>arr[i];
    }
    
    int target=8;
    Solution sol;
    int result=sol.search(arr,size,target);
    std::cout<<"target is at index: "<<result<<std::endl;


    return 0;
}
// You define a function normally, outside the struct.
// Struct is just for grouping data, not behavior.
// In C++:
// Functions inside a class are usually accessed through objects.
// But with static, you can access them like global functions under a namespace (class).

