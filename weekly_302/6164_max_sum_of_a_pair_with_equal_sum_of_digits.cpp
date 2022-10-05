#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sum_digits(int num){
        int temp = 0;
        int sum = 0;
        while(num>0){
            temp = num%10;
            sum+=temp;
            num = num/10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> um;
        int temp_sum = 0;
        int max_sum = 0;
        int old_num = 0;
        for(int i = 0; i< n; i++){
            temp_sum = sum_digits(nums[i]);
            if(um.find(temp_sum)==um.end()){
                um.insert({temp_sum, nums[i]});
            }
            else{
                old_num = um[temp_sum];
                max_sum = max(old_num+nums[i], max_sum);
                um[temp_sum] = max(old_num,nums[i]);
            }
        }
        return max_sum;      
    }
};