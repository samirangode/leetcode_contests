#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        unordered_map<int, int> um;
        int prefix_sum = 0, max_sum = 0;
        while(k<n){
            if(um.find(nums[k])==um.end()){
                prefix_sum+=nums[k];
                um.insert({nums[k],prefix_sum});
                max_sum = max(prefix_sum, max_sum);
            }
            else{
                int temp_sum = um[nums[k]];
                um.erase(nums[k]);
                prefix_sum -= temp_sum;
                continue;
            }
            k++;
        }
        return max_sum;      
    }
};
