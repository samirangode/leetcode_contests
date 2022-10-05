#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> um;
        map<int, unordered_set<int>> m;
        for(int i = 0; i< n; i++){
            if(m.size()<k){
                if(m[um[nums[i]]].count(nums[i])){
                    m[um[nums[i]]].erase(nums[i]);
                }
                um[nums[i]]++;
                m[um[nums[i]]].insert(nums[i]);
                continue;
            }
            if(um[nums[i]]+1 >= m.rbegin()->first){
                if(m[um[nums[i]]].count(nums[i])){
                        m[um[nums[i]]].erase(nums[i]);
                }
                um[nums[i]]++;
                m[um[nums[i]]].insert(nums[i]);
                if(m.size()>k){
                    m.erase(prev(m.end()));
                }
            }else{
                um[nums[i]]++;
            }
        }
        unsigned int total = 0;
        vector<int> ans;
        for(auto it : m){
            for(int i : it.second){
                if(total==k) return ans;
                ans.push_back(i);
                total++;
            }
        }
        return ans;      
    }
};
