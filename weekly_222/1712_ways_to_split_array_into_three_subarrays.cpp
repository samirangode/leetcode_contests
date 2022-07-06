#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int count_bet(vector<int> &a, int ind, int low, int high){
        if(low> high) return 0;

        auto l_itr = lower_bound(a.begin(), a.begin() + ind, low);
        auto r_itr = upper_bound(a.begin(), a.begin()+ ind, high);

        return r_itr - l_itr;
    }
    
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9+7;
        auto pref = nums;

        for(int i = 1; i < n ;i++){
            pref[i] += pref[i-1];
        }

        int sum = pref.back();

        long long cnt = 0;
        int suf = 0;
        for(int i = n-1; i>=2;i--){
            suf+=nums[i];
            auto in_bet = count_bet(pref, i -1,sum - 2*suf, (sum- suf)/2);
            cnt = (cnt + in_bet)%mod;
        }

        return cnt;
        
    }
};