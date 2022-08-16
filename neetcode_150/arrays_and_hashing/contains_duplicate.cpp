#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(int i = 0; i< n; i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
            }
            else{
                return true;
            }
        }
        return false;      
    }
};
