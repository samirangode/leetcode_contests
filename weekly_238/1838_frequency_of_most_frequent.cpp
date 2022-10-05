#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Shrinkable
        // int i = 0; int j = 0; int ans =1; 
        // int N = nums.size();
        // long long sum = 0;
        // sort(nums.begin(),nums.end());
        // for(;j<N;j++){
        //     sum+=nums[j];
        //     while(1ll*(j-i+1)*nums[j] - sum > k) sum-=nums[i++];
        //     ans = max(ans, j-i+1);
        // }
        // return ans;

        //Non shrinkable
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int N = nums.size();
        long long sum = 0;
        for(;j<N;j++){
            sum+=nums[j];
            if(1ll*(j-i+1)*nums[j] - sum > k){
                sum-=nums[i++];
            }
        }        
        return j-i;
    }
};
