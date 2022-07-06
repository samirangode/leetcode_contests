#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int mini =INT_MAX;
        for(int i = 0; (i+k-1)<=(n-1); i++){
            mini = min(mini, nums[i+k-1] - nums[i]);
        }

        return mini;
        
    }
};