#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f(int index, int k, vector<vector<int>>& piles, vector<vector<int>> &dp){
        if(index == piles.size() || k==0){
            return 0;
        }
        if(dp[index][k]!=-1) return dp[index][k];
        int best = f(index+1, k, piles, dp);
        int sum = 0;
        for(int i=0; i<min((int)piles[index].size(),k); i++){
            sum +=piles[index][i];
            best = max(best, sum + f(index+1, k - (i+1), piles, dp));

        }
        dp[index][k] = best;
        return dp[index][k];
    }
    
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size(), vector<int> (k+1,-1));
        return f(0,k,piles,dp);
    }
};
