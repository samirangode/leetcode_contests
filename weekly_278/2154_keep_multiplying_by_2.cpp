#include <bits/stdc++.h>>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> um;
        int n = nums.size();
        bool found = false;
        for(int i = 0; i<n; i++){
            um[nums[i]]++;
            if(nums[i]==original){
                found = true;
            }
        }
        while(found==true){
            if(um.find(original)!=um.end()){
                original = 2*original;
            }else{
                found = false;
            }
        }
        return original;
        
    }
};


