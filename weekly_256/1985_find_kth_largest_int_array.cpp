#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();

        vector<long long> num_int;
        num_int.reserve(n);
        for(int i = 0; i <n; i++){
            num_int.push_back(stoll(nums[i]));
        }
        sort(num_int.begin(),num_int.end());
        return to_string(num_int[k-1]);
    }
};