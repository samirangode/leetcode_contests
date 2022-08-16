#include <bits/stdc++.h>

using namespace std;
// simple recusive
// class Solution {
// public:
//     int f(int index, int prev_ind, vector<int> &nums){
//         if(index == nums.size()){
//             return 0;
//         }
//         // not taken
//         int length = 0 + f(index+1, prev_ind, nums);
//         // taken
//         if(prev_ind==-1 || nums[index]>nums[prev_ind]){
//             length = max(length, 1 + f(index+1,index, nums));
//         }
//         return length;

//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         // int n = nums.size();
//         return f(0,-1,nums);
//     }
// };
// with memoisation
// class Solution {
// public:
//     int f(int index, int prev_ind, vector<int> &nums, vector<vector<int>> &dp){
//         if(index == nums.size()){
//             return 0;
//         }
//         if(dp[index+1][prev_ind+1]!=-1) return dp[index+1][prev_ind+1];
//         // not taken
//         int length = 0 + f(index+1, prev_ind, nums,dp);
//         // taken
//         if(prev_ind==-1 || nums[index]>nums[prev_ind]){
//             length = max(length, 1 + f(index+1,index, nums, dp));
//         }
//         return dp[index+1][prev_ind+1]=length;

//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
//         return f(0,-1,nums, dp);
//     }
// };
// Bottom up
// Bottom up
// class Solution {
// public:
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+2, vector<int>(n+1,0));
//         // for(int i = 0; i< n+1; i++){
//         //     dp[n][i] = 0;
//         // }
//         for(int ind = n-1; ind>=0; ind--){
//             for(int prev_ind = ind -1; prev_ind>=-1; prev_ind-- ){
//                 int length = 0 + dp[ind+1+1][prev_ind+1];
//                 // taken
//                 if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
//                     length = max(length, 1 + dp[ind+1+1][ind+1]);
//                 }
//                 dp[ind+1][prev_ind+1]=length;
//             }
//         }
        
//         // return f(0,-1,nums, dp);
//         return dp[1][0];
//     }
// };
// // Improved solution
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,1);
//         int final_max = 1;
//         for(int i = 0; i<n; i++){
//             for(int j = 0; j < i; j++){
//                 if(nums[i]> nums[j])
//                     dp[i] = max(dp[i], dp[j]+1);
//             }
//             final_max = max(dp[i],final_max);
//         }
//         return final_max;        
//         // for(int c : dp){
//         //     final_max = max(c, final_max);
//         // }
//     }
// };
// Intelligently build a subsequence

