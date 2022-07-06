#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        for(int i = 0; i< n; i++){
            capacity[i] -=rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(capacity[i]==0) ans++;
            else{
                if(additionalRocks >= capacity[i]){
                    additionalRocks - capacity[i];
                    capacity[i] = 0; ans++;
                }else{
                    break;
                }
            }
        }
        return ans;        
    }
};
