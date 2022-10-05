#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // int maxScore(vector<int>& nums) {
    //     int n = nums.size()/2;
    //     // vector<vector<int>> dp(2*n, vector<int>(2*n));
    //     vector<pair<int,pair<int,int>>> vals;
    //     unordered_set<int> us;
    //     for(int i = 0 ; i< 2*n; i++){
    //         us.insert(i);
    //         for(int j = i+1; j< 2*n; j++){
    //             // dp[i][j] = __gcd(nums[i],nums[j]);
    //             vals.push_back({__gcd(nums[i],nums[j]), {i,j}});
    //         }
    //     }
    //     sort(vals.begin(),vals.end());
    //     int k = vals.size();
    //     vector<int> final;
    //     for(int i=k-1; i>=0; i--){
    //         auto temp = vals[i];
    //         int a = temp.second.first;
    //         int b = temp.second.second;
    //         if(us.find(a)!=us.end()&& us.find(b)!=us.end()){
    //             final.push_back(temp.first);
    //             us.erase(a); us.erase(b);
    //         }
    //     }
    //     int score = 0;
    //     for(int i = n; i>=1 ; i--){
    //         score+=i*final[i-1];
    //     }
    //     return score;
    // }
    int gcdMemo[14][14];
    int memo[1<<14] = {};
    int m, n;
    int maxScore(vector<int> &nums){
        m = nums.size(); n = m/2;
        return dp(nums, 1, 0);
    }
    // mask basically, keeps track of all the elements that have been
    // used before. mask >> i basically right shifts the entire sequence
    // by i, so mask>>i & 1 will check if the index i was used before
    // 
    int dp(vector<int>& nums, int op, int mask){
        if(op > n) return 0; // base case n oprations done
        if(memo[mask]!=0) return memo[mask];

        for(int i =0; i< m; i++){
            if((mask>>i) & 1) continue; // checks if nums[i] is used in the mask
            for(int j = 0; j< m; j++){
                if((mask>>j)& 1) continue;
                int newMask = (1<<i) | (1<<j) | mask;
                int score = op* gcd(nums,i,j) + dp(nums, op +1, newMask);
                memo[mask] = max(memo[mask],score); 
            }
        }
        return memo[mask];
    }
    int gcd(vector<int>& nums, int i, int j){
        if(gcdMemo[i][j]) return gcdMemo[i][j];
        return gcdMemo[i][j] = __gcd(nums[i], nums[j]);
    }
};