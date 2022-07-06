#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int totalOps = 0; int ops = 0;
        for(int i = 1; i< n;i++){
            prev = nums[i-1];
            if(nums[i]>prev){
                continue;
            }
            ops+=prev+1-nums[i];
            totalOps+=ops;
        }
        return totalOps;   
    }
};
