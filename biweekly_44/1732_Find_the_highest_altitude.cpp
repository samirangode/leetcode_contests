#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi= 0; int new_val = 0;
        int n = gain.size();
        for(int i = 0; i< n ; i++){
            new_val += gain[i];
            maxi = max(maxi, new_val);
        }
        return maxi;
    }
};