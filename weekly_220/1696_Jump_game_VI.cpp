#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,INT_MIN);
        dp[n-1] = 0;
        int max_sum = 0, sum = 0;
        for(int index = n-2; index >=0; index--){
            max_sum = 0, sum = 0;
            for(int i = 1; i<=k; i++){
                if((index+i) < n ){
                    sum = nums[index+ i] + dp[index];
                    max_sum = max(sum, max_sum); 
                }
            }
            dp[index] = max_sum;
        }
        return dp[0];
    }
};