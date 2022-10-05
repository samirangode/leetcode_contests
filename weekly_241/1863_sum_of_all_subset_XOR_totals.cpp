#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int final = 0;
        for(int i = 0; i< n ; ++i){
            final = final | nums[i];
        }
        return final * pow(2,n-1);      
    }
};