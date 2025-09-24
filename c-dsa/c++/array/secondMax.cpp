#include<iostream>
using namespace std;
class Solution{

    public:
    int secMax(int arr[],int n){
        int max=INT8_MIN;
        int secmax=INT8_MIN;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]>max){
                max=arr[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(arr[i]>secmax&&arr[i]!=max){
                secmax=arr[i];
            }
        }
        
        
        return secmax;

    }

};
int main() {
    int arr[]={1,9,7,4,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    Solution s;
    int result=s.secMax(arr,size);
    cout<<"second max number in array: "<<result<<endl;
    
    return 0;
}

//missing no. given  
// class Solution {
//   public:
//     int missingNum(vector<int>& arr) 
//     {
//         long long n = arr.size() + 1;
//         long long sum = 0;
//         for (int i = 0; i < arr.size(); i++) {
//             sum += arr[i];
//         }
//         long long sumOfN = (n * (n + 1)) / 2;
//         return (int)(sumOfN - sum);
//     }
// };
