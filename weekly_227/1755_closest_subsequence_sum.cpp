#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mini = INT_MAX;
    int helper(vector<int>& nums, vector<vector<vector<int>>> &dp, int i, int goal,int sign){
        if(i == 0){
            return abs(nums[0] - goal)<abs(0-goal) ? nums[0]:0;
        }
        if(dp[i][abs(goal)][sign]!=INT_MIN){
            return dp[i][abs(goal)][sign];
        }
        int sum1 = nums[i] + helper(nums,dp,i-1,goal-nums[i], sign);
        int sum2 = helper(nums,dp,i-1,goal,sign);
        if(abs(sum1-goal)<=abs(sum2-goal)){
            mini = min(mini, abs(sum1-goal));
            return dp[i][abs(goal)][goal<0] = sum1;
        }else{
            mini = min(mini, abs(sum2 - goal));
            return dp[i][abs(goal)][goal<0] = sum2;
        }
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        // int dp[n][(int)1e9][2] = { INT_MIN };
        vector<vector<vector<int>>> dp(n, vector<vector<int>>((int)1e9, vector<int>(2, INT_MIN)));
        helper(nums,dp,n-1,goal,goal<0);
        return mini;

    }
};
