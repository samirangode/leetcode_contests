#include <bits/stdc++.h>

using namespace std;



class Solution {
private:
    void minDiffHelper(vector<int> &nums, int index, long long one, int one_i, long long two, int two_i, vector<long long> &ans){
        int n = nums.size();
        if(index == n){
            if(one_i==n/2 && two_i ==n/2)
            {
                long long temp = abs(one -two);
                ans.push_back(temp);
                return;
            }
        }
        if(one_i> n/2 || two_i> n/2){
            return;
        }
        int new_val = nums[index];
        //give one
        minDiffHelper(nums,index+1,one+new_val,one_i+1,two,two_i,ans);

        //give two
        minDiffHelper(nums,index+1,one,one_i,two+new_val,two_i+1,ans);

        return;
    }
public:
    int minimumDifference(vector<int>& nums) {
        vector<long long> ans;
        
        minDiffHelper(nums, 0,0,0,0,0,ans);

        long long min = LONG_LONG_MAX;
        for(long long i : ans){
            if(i<min){
                min = i;
            }
        }

        return (int)min;
    }
};
