#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        bool ascending = true;
        int n = nums.size();
        int max_sum = INT_MIN;
        int part_sum = 0;
        for(int i = 0; i <n;i++){
            part_sum = 0;
            ascending = true;
            for(int j = i; j< n; j++){
                if(j!=i){
                    if(nums[j]<=nums[j-1]){
                        ascending = false;
                        break;
                    }
                }
                part_sum+=nums[j];
                max_sum = max(part_sum, max_sum);
            }
        }
        return max_sum;        
    }
};
