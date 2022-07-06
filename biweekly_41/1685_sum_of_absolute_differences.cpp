#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum(n,0);
        for(int i = 0 ;i <n; i++){
            if(i==0){
                prefix_sum[0] = nums[0];
                continue;
            }
            prefix_sum[i]= prefix_sum[i-1] + nums[i];
        }
        vector<int> result(n,0);
        int before = 0;
        int after = 0;
        for(int i =0;i<n;i++){
            before = -1*prefix_sum[i] + (i+1)*nums[i];
            after = prefix_sum[n-1] - (n-i+1)*nums[i];
            result[i] = before+after;
        }
        return result;
    }
};
