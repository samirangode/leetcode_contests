#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> um;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            // if(um.find(nums[i])==um.end()){
            //     um[nums[i]]++;
            // }
            // else{

            // }
            um[nums[i]]++;    
        }
        int pairs = 0;
        int left = 0;
        for(auto it : um){
            int div = it.second/2;
            pairs+=div;
            int rem = it.second%2;
            left+=rem;
        }
        vector<int> ans{pairs,left};      
        return ans;
    }
};
