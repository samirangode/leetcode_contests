#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        unordered_set<int> ans_set;
        // int ans;
        for(int num : nums){
            ans_set.insert(num);
        }
        // ans+=ans_set.size();
        vector<int> ans_vec;
        for(auto it : ans_set){
            ans_vec.push_back(it);
        }
        int n = ans_vec.size();
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                ans_set.insert(__gcd(ans_vec[i],ans_vec[j]));
            }
        }
        return ans_set.size();
        
    }
};
