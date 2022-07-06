#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i]<mini){
                mini = nums[i];
            }
            if(nums[i]>maxi){
                maxi = nums[i];
            }
        } 
        int p = maxi;
        int q = mini;
        int temp;
        while(q!=0){
            temp = p%q;
            p = q;
            q =temp;
        }
        return p;
    }
};