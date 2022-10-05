#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // best time to buy sell stocks
        int maxi = 0;
        int min_price= INT_MAX;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            min_price = min(min_price, nums[i]);
            maxi = max(maxi, nums[i] - min_price);
        }
        return maxi == 0? -1:maxi; 
    }
};