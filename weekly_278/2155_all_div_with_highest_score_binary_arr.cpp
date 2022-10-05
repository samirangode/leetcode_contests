#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n+1,0);
        vector<int>suffix(n+1,0);
        for(int i = 1; i<= n; i++){
            if(nums[i-1]==0){
                
                prefix[i] = prefix[i-1]+1;
            }else{
                prefix[i]=prefix[i-1];
            }
            if(nums[n-1]==1){
                suffix[n-i] = suffix[n-i+1] + 1;
                
            }else{
                suffix[n-i] = suffix[n-i+1];
            }
        }
        int sum = 0;
        int max = 0;
        int ans_num = 0;
        for(int i  = 0; i <=n; i++){
            sum = prefix[i]+suffix[i];
            if(sum == max){
                // ans.push_back(i);
                ans_num++;
            }
            if(sum>max){
                // ans.clear();
                ans_num = 1;
                // ans.push_back(i);
                max = sum;
            }
        }
        vector<int> ans(ans_num);
        for(int i = 0; i<=n; i++){
            sum = prefix[i] + suffix[i];
            if(sum == max){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
