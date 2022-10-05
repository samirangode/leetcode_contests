#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> us;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            if(nums[i]>0){
                us.insert(nums[i]);
            }
        }
        return us.size();
    }
};
