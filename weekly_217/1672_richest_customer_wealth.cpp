#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        int n = accounts[0].size();
        int max_wealth = INT_MIN;
        int wealth = 0;
        for(int i =0; i<m ;i ++){
            wealth = 0;
            for(int j=0; j<n; j++){
                wealth+=accounts[i][j];
            }
            max_wealth = max(wealth, max_wealth);
        }
        return max_wealth;      
    }
};
