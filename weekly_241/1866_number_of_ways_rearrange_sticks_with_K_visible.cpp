#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<long long>> dp;
    long long mod = 1e9+7;
    long long calcTotal(int n , int k){
        if(k==0 || k> n) return 0;
        if(n<=2) return 1;

        if(dp[n][k]!= -1) return dp[n][k];
        
        long long ans = 0;

        ans += calcTotal(n-1,k-1);

        ans+= (n-1) * calcTotal(n-1,k);
        ans%=mod;
        dp[n][k] = ans;
        return dp[n][k];
    }
    
    int rearrangeSticks(int n, int k) {
        dp = vector<vector<long long >> (n+1, vector<long long >(k+1,-1));
        long long val = calcTotal(n,k);
        return val%mod;
    }
};
