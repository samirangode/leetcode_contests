#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int mid = 0;
        while(low<=high){
            mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }else if(target > nums[mid]){
                low = mid+1;
            }else if(target < nums[mid]){
                high = mid - 1;
            }
        }
        return -1;      
    }
};
