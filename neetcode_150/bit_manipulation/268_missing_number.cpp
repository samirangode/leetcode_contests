#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_val = n;
        for(int i = 0; i< n ;i++){
            xor_val = xor_val ^ i ^ nums[i];
        }
        return xor_val;      
    }
};
