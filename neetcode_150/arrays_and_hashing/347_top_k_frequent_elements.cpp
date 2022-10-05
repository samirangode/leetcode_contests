#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> um;
        for(int temp : nums){
            um[temp]++;
        }
        vector<vector<int>> bucket(n);
        for(auto it : um){
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = n-1; i>=0 && ans.size()<=k; i--){
            for(int num : bucket[i]){
                ans.push_back(num);
                if(ans.size()>k-1) break;
            }
        }
    }
};
