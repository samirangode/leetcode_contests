#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = nums[0];
        int n = nums.size();
        for(int i =1 ; i< n; i++){
            num = num ^ nums[i];
        }
        return num;
    }
};
