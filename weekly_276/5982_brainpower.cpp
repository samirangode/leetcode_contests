#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long dp[n];
        dp[n-1] = questions[n-1][0];
        for(int i = n-2; i>0; i--){
            long long bp = questions[i][1];
            long long points = questions[i][0];

            if((i + bp+1) < n){
                long long val = max(dp[i+1], dp[i + bp+1] + points);
                dp[i] = val;
            }
            else{
                long long val = max(dp[i+1], points);
                dp[i] = val;
            }
        }
        return dp[0];
    }
};