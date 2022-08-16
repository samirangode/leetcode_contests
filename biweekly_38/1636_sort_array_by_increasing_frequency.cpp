#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> um;
        for(int i =0; i<n;i++){
            um[nums[i]]++;
        }
        map<int,priority_queue<int>> m;
        for(auto it: um){
            m[it.second].push(it.first);
        }
        vector<int> ans;
        for(auto it: m){
            while(!it.second.empty()){
                for(int j = 0; j< it.first; j++){
                    ans.push_back(it.second.top());
                }
                it.second.pop();
            }
        }
        return ans;      
    }
};
