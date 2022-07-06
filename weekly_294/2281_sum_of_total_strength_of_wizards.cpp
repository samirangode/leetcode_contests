#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int mod = 1e9 + 7;
        int n = strength.size();
        int totalSum = 0, sum=0, min_val=0;
        for(int i = 0; i<n; i++){
            sum = strength[i];
            min_val = strength[i];
            for(int j = i ; j<n; j++){
                min_val = min(strength[j],min_val);
                sum = (sum + strength[j])%mod;
                totalSum = (totalSum + (min_val * sum)%mod)%mod;
            }
        }      
        return totalSum;
    }
};
