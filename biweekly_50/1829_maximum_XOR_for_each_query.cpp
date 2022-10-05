#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> all_bits(maximumBit);
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = 0; j<maximumBit;j++){
                if((nums[i]&(1<<j)) >0){
                    all_bits[j]+=1;
                }
            }
        }
        vector<int> ans(n);
        int k = n-1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<maximumBit;j++){
                if(all_bits[j]%2 == 0){
                    ans[i]+= 1<<j;
                }
            }
            for(int j = 0; j<maximumBit;j++){
                if((nums[k]&(1<<j)) >0){
                    all_bits[j]-=1;
                }
            }
            k--;
        }
        return ans;      
    }
};
