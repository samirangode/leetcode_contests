#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        long long dp[m][n];

        for (int j = 0; j < n; j++)
        {
            dp[0][j] = points[0][j];
        }
        long long maxi;
        long long ans = LONG_LONG_MIN;
        for(int i  = 1; i < m; i++){
            for(int j = 0; j<n; j++){
                maxi = LONG_LONG_MIN;
                for(int k = 0; k < n; k++){
                    maxi = max(maxi, 1ll*(dp[i-1][k] - abs(k-j)));
                }
                dp[i][j] = points[i][j] + maxi;
                if(i == n-1){
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        // long long ans = LONG_LONG_MIN;
        // for(int j = 0; j < n; j++){
        //     ans = max(ans, dp[m-1][j]);
        // }
        return ans;

        
    }
};
