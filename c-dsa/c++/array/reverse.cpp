#include<iostream>
using namespace std;
class Solution{
    public:
    int *reverse(int arr[],int n){
        int *rev=new int[n];
        for (int i = 0; i<n; i++){
            rev[n-i-1]=arr[i];
        }

        return rev;
    }
};



int main(){
    int *arr;
    int size=5;
    arr=new int[size];
    cout<<"enter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    Solution sol;
    int *result=sol.reverse(arr,size);
    for (int i = 0; i < size; i++) {
        cout << result[i] << " ";
    }
    cout << endl;


    return 0;
}

//-----------------------------------------------
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int>result;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == target) {
//                 result.push_back(i);
//                 break;
//             }
//         }
//         for (int j = nums.size() - 1; j >= 0; j--) {
//             if (nums[j] == target) {
//                 result.push_back(j);
//                 break;
//             }
//         }
//         if (result.empty()) {
//             return {-1, -1};
//         }

//         if (result.size() == 1) {
//             result.push_back(result[0]);
//         }

//         return result;
//     }
// };

// In C++, when you write something like:

// return {first, last};
// You're using uniform initialization (also called list initialization), and yes, it creates a temporary std::vector<int> if the return type is vector<int>.
//here q already given sorted array so we can use binsry search and logn time