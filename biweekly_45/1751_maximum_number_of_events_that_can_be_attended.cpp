#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxi;
    int helper(vector<vector<int>> &events, int ind, int prev_ind, int k){
        if(ind == events.size()) return 0;
        if(k == 0) return 0;

        int not_taken = helper(events, ind+1, prev_ind, k);
        if(prev_ind == -1 || events[ind][0]>events[prev_ind][1]){
            int taken = helper(events, ind+1, ind,k-1);
            maxi = max(maxi, max(not_taken, taken));
            return max(not_taken, taken);

        }
        maxi = max(not_taken, maxi);
        return not_taken;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        // helper(events, 0,-1,k);
        // return maxi;
        int n = events.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1)));
        for(int prev_ind=n-1; prev_ind>=-1;prev_ind--){
            for(int cap = 0; cap<=k; cap++){
                dp[n][prev_ind][cap] = 0;
            }
        }
        for(int ind = n; ind>=0; ind--){
            for(int prev_ind = n-1; prev_ind>=-1; prev_ind--){
                dp[ind][prev_ind][0] = 0;
            }
        }
        for(int ind = n-1; ind>=0; ind--){
            for(int prev_ind = ind-1; prev_ind>=-1; prev_ind--){
                for(int cap = 0; cap<=k; cap++){
                    int val = 0 + dp[ind+1][prev_ind+1][cap];
                    if(prev_ind==-1 || events[ind][0]>events[prev_ind][1]){
                        val = max(val, events[ind][2]+dp[ind+1][ind+1][cap-1]);
                    }
                    maxi = max(maxi, val);
                    dp[ind][prev_ind+1][cap] = val;
                }
            }
        }
        return maxi;
    }
};
