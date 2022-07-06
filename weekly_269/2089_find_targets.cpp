#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        int hi = nums.size()-1;
        int li = 0;
        int high = nums.size()-1;
        int low = 0 ;
        int mid = 0;
        //hi
        while(low<=high){
            mid = low + (high - low)/2;
            if(nums[mid] == target){
                if(mid == n-1){
                    hi = n-1;
                    break;
                }
                if(nums[mid%n]!=nums[(mid+1)%n]){
                    hi = mid;
                    break;
                }
                if(nums[mid% n] == nums[(mid+1)%n]){
                    low = mid+1;
                }
            }
            if(target>nums[mid]){
                low = mid+1;
            }
            if(target<nums[mid]){
                high = mid-1;
            }
        }
        if(low>high){
            return ans;
        }
        //li
        high = n-1;
        low = 0;
        mid = 0;
        while(low<=high){
            mid = low + (high - low)/2;
            if(nums[mid] == target){
                if(mid == 0){
                    li = 0;
                    break;
                }
                if(nums[mid%n]!=nums[(mid-1)%n]){
                    li = mid;
                    break;
                }
                if(nums[mid% n] == nums[(mid-1)%n]){
                    high = mid-1;
                }
            }
            if(target>nums[mid]){
                low = mid+1;
            }
            if(target<nums[mid]){
                high = mid-1;
            }
        }
        for(int i = li; i<=hi;i++){
            ans.push_back(i);
        }
        return ans;    
    }
};