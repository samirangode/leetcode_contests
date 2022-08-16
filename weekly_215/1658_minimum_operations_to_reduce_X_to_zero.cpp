#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int current = 0;
        int sum = 0;
        for(int i =0; i<n; i++){
            sum+=nums[i];
        }
        int required = sum - x;
        int left = 0; int right = 0;
        int max_length = 0;
        for(; right<n;){
            if(left>right) return -1;
            if(current<required){
                current+=nums[right];
                right++;
            }
            if(current==required){
                max_length = max(max_length,right - left +1);
            }
            if(current>required){
                current-=nums[left];
                left++;
            }
        }
        return max_length;        
    }
};
