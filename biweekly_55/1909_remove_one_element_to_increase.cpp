#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int count = 0;
        while(i<n-1){
            if(nums[i]<nums[i+1]){
                i++;
            }else{
                
                    if((i!=n-2) && nums[i]<nums[i+2]){
                        count++;
                    }
                    else if((i!=0) && nums[i+1]>nums[i-1]){
                        count++;
                    }
                    else{
                        return false;
                    }
                
            }
            if(count>1){
                return false;
            }
        }

        return true;
        
    }
};
