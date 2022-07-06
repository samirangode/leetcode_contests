#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int sum  = 0;
        int n = coins.size();
        for(int i  = 0; i < n ; i++){
            if(coins[i]<=sum+1) sum+=coins[i];
        }
        return sum+1;      
    }
};
