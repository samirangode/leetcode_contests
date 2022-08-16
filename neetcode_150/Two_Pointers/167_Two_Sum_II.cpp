#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<int,int> um;
//         for(int i = 0; i< n; i++){
//             if(um.find(target-nums[i])!=um.end()){
//                 vector<int> v{um[target-nums[i]]+1, i+1};
//                 return v;
//             }else{
//                 um[nums[i]] = i;
//             }
//         }
//         vector<int> v{-1,-1};
//         return v;      
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        int i =0,j=n-1;
        vector<int> ans;
        while(i<j){
            sum = nums[i] + nums[j];
            if(sum==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if(sum>target){
                j--;
            }else if(sum<target){
                i++;
            }
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;        
    }
};
