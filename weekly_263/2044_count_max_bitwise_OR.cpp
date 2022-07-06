#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int,int> um;
    void countMaxOrSubsetsHelper(int index,int OR,vector<int>& nums) {
        if(index = nums.size()){
            um[OR]++;
            return;
        }
        int val = nums[index];
        //leave it
        countMaxOrSubsetsHelper(index+1, OR, nums);
        
        
        //take it
        OR = OR|val;
        countMaxOrSubsetsHelper(index+1, OR, nums);

        
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        countMaxOrSubsetsHelper(0,0,nums);
        int mx = 0;
        int ans = 0;
        for(auto it: um){
            if(it.first>mx){
                ans = it.second;
            }
        }
        return ans;
    }
};