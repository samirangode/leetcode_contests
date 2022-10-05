#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res(queries.size(),-1);
        sort(intervals.begin(),intervals.end(),[](const auto& a, const auto& b ){return a[1]-a[0] < b[1]-b[0];});
        set<pair<int,int>> s;
        int m = queries.size();
        for(int i = 0; i < m; i++){
            s.insert({queries[i],i});
        }
        for(auto interval : intervals){
            auto it = s.lower_bound({interval[0],0});
            while(it!=s.end() && it->first<= interval[1]){
                res[it->second] = interval[1] - interval[0] +1;
                s.erase(it);
                it++;
            }
        }
        return res;            
    }
};