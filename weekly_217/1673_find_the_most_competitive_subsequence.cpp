#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // deque<int> dq;
        // int n = nums.size();
        // for(int i = 0; i<n; i++){
        //     if(dq.empty()){
        //         dq.push_back(nums[i]);
        //         continue;
        //     }
        //     while(dq.front()>nums[i] && dq.size()-1 + n - i >=k){
        //         dq.pop_back();
        //     }
        //     dq.push_back(nums[i]);
        // }
        // vector<int> result;
        // for(int i = 0; i<k; i++){
        //     result.push_back(dq.front());
        //     dq.pop_front();
        // }
        // return result;
        vector<int> result;
        int n = nums.size();
        for(int i = 0; i<n;i++){
            while(!result.empty() && result.back()>nums[i] &&result.size()-1+n - i>=k){
                result.pop_back();
            }
            if(result.size()<k){
                result.push_back(nums[i]);
            }   
        }
        return result;
    }
};