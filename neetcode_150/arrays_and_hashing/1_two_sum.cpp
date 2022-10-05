#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> us;
        int n = nums.size();
        us.insert({nums[0],0});
        vector<int> ans;
        for(int i = 1; i<n;i++){
            if(us.find(target-nums[i])!=us.end()){
                ans.push_back(us[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            us.insert({nums[i],i});
        }
        return ans;      
    }
};