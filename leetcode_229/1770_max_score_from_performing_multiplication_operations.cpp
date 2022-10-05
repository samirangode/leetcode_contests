#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f(int index, int start, int end, vector<int>& nums, vector<int>& multipliers, vector<int> &dp){
        if(index == multipliers.size()) return 0;
        if(dp[index]!=-1){
            return dp[index];
        }

        int left = nums[start]*multipliers[index] + f(index+1,start+1,end,nums,multipliers,dp);
        int right = nums[end]*multipliers[index] + f(index+1,start,end-1,nums,multipliers,dp);

        return dp[index] = max(left, right);
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<int> dp(multipliers.size(),-1);
        return f(0,0,nums.size()-1,nums,multipliers,dp);
    }
};
