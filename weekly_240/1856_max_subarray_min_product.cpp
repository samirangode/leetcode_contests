#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        long long prefixSum[n];
        prefixSum[0] = nums[0];
        for(int i = 1; i<n;i++){
            prefixSum[i]= prefixSum[i-1] + nums[i];
        }
        stack<pair<int,int>> s_left, s_right;
        int left[n], right[n];
        int count = 0;
        for(int i = 0; i<n;i++){
            count = 1;
            while(!s_left.empty() && s_left.top().first > nums[i]){
                count += s_left.top().second;
                s_left.pop();
            }
            s_left.push({nums[i],count});
            left[i] = count;
        }
        for(int i = n-1; i>=0 ; i--){
            count = 1;
            while(!s_right.empty() && s_right.top().first >= nums[i]){
                count += s_right.top().second;
                s_right.pop();
            }
            s_right.push({nums[i],count});
            right[i] = count;
        }
        long long int res = 0;
        for(int i = 0; i<n; i ++){
            int a = i - left[i] + 1;
            int b = i + right[i] - 1;
            long long int  subArraySum;
            if(a>0){
                subArraySum = prefixSum[b] - prefixSum[a-1];
            }
            else{
                subArraySum = prefixSum[b];
            }
            res = max(res,subArraySum*nums[i]);
        }
        return res%(1000000007);

    }
};