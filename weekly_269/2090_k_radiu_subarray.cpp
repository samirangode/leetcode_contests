#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0){
            return nums;
        }
        
        int n = nums.size();
        vector<int> ans;
        ans.resize(n);
        if(k>=float(n/2)){
            for(int i = 0; i<n; i++){
                ans[i] = -1;
            }
            return ans;
        }
        for(int i = 0; i <k; i++){
            ans[i] = -1;
            ans[k] = nums[i] + nums[2*k - i];
            ans[n-1-i] = -1;
        }
        ans[k]+= nums[k];
        ans[k] = ans[k]/(2*k+1);
        int i = k+1;
        int val = 0;
        while(i <= n-1-k){
            val = ans[i-1]*(2*k+1) - nums[i-k-1] + nums[i + k];
            val = val/(2*k+1);
            ans[i] = val;           
            i++;
        }
        return ans;
    }
};