#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> um;
        int n = nums.size();
        for(int i = 0; i<n;i++){
            um[nums[i]]++;
        }
        vector<int> ans;
        for(pair<int,int> a : um){
            if(a.second==1 && um.find(a.first-1)==um.end() && um.find(a.first+1)==um.end()){
                ans.push_back(a.first);
            }
        }
        return ans;
        
    }
};