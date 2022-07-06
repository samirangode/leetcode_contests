#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int count  =0 ;
        long long left = nums[0];
        unordered_map<int, vector<int>> um;
        um[nums[0]].push_back(0);
        long long right = 0;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            right+=nums[i];
            um[nums[i]].push_back(i);
        }
        long long diff = 0;
        if(right == left){
            count++;
        }
        for(int j = 2; j<n; j++){
            left+=nums[j-1];
            right-=nums[j-1];
            diff = abs(right-left);
            if(right==left){
                count++;
                continue;
            }
            int val = k- diff;
            if(um.find(val)!=um.end()){
                auto it = um[val];
                for(auto& i: it){
                    if(i<j){
                        if((left+k-nums[i]) == right){
                            count++;
                        }
                    }
                    else{
                        if(left == (right + k -nums[i])){
                            count++;
                        }
                    }
                }
            }
        }      
    }
};