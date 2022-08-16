#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int removal = n/20;
        sort(arr.begin(),arr.end());
        int mean = 0;
        int den = 0;
        for(int i = removal; i < n - removal; i++ ){
            mean+=arr[i];
            den++;
        }
        double ans = mean / den;
        return ans;
    }
};
