#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        int arr[n];
        // int min = INT_MAX;
        arr[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            arr[i] = min(nums[i],arr[i+1]);
        }
        int sum = 0;
        int maxi = arr[0];
        for(int i =1;i<n-1; i++){
            if((nums[i]>nums[i-1]) && (nums[i]<nums[i+1])){
                sum+=1;
            }
            if(nums[i]>maxi && nums[i]<arr[i+1]){
                sum+=1;
            }
            maxi = max(nums[i],maxi);
        }
        return sum;
    }
};
