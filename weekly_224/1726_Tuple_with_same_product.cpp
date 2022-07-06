#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> um;
        for(int i =0; i<n;i++){
            for(int j = i+1;j<n ;j++){
                um[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;
        for(auto it : um){
            ans+=it.second - 1;
        }
        return ans;      
    }
};
