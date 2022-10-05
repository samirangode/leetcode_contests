#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        long long max_len = 0;
        long long temp_len = 0;
        int n = nums.size();
        unordered_set<int> us;
        for(int i = 0; i<n; i++){
            us.insert(nums[i]);
        }
        while(!us.empty()){
            int top = *us.begin();
            int prev_top = top;
            int prev_len =0, top_len = 0;
            while(us.find(prev_top-1)!=us.end()){
                prev_top = prev_top-1;
                prev_len++;
                us.erase(prev_top);
            }
            int forward_top = top;
            while(us.find(forward_top+1)!=us.end()){
                forward_top = forward_top+1;
                top_len ++;
                us.erase(forward_top);
            }
            us.erase(top);
            temp_len = prev_len + top_len +1;
            max_len = max(max_len, temp_len);
        }
        return max_len;      
    }
};
