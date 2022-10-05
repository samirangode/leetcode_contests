#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1);
        prefix[0] = 1;
        vector<int> suffix(n+1);
        suffix[n] = 1;
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            // ans.push_back(prefix)
            prefix[i+1] = prefix[i] * nums[i];
            suffix[n-i-1] = suffix[n-i] * nums[n-i-1];
        }
        for(int i = 0; i<n;i++){
            ans[i] = prefix[i]*suffix[i+1];
        }
        return ans;

    }
};
