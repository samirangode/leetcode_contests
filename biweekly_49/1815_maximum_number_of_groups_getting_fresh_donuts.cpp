
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<vector<int>,int> dp;
    
    int dfs(vector<int> &cnt, int left){
        auto it = dp.find(cnt);
        if(it!=end(dp)){
            return it->second;
        }
        int res = 0, bz = cnt.size();
        for(int i = 1; i< bz; ++i){
            if(--cnt[i] >= 0){
                res = max(res, (left == 0)+dfs(cnt, (bz + left - i)%bz));
            }
            ++cnt[i];

        }
        return dp[cnt];
    }
    int maxHappyGroups(int bz, vector<int>& groups) {
        vector<int> cnt(bz);
        int res = 0;
        for(auto group : groups){
            if(group % bz == 0)
                ++res;
            else if(cnt[bz - group%bz]){
                --cnt[bz - group%bz];
                ++res;
            }
            else{
                ++cnt[group%bz];
            }
        }
        return dfs(cnt, 0) +res;

    }
};