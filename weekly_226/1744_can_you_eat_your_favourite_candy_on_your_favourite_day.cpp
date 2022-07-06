#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        int m = queries.size();

        vector<bool> ans(n, true);
        for(int i =0; i<n;i++){
            if(i==0) continue;
            candiesCount[i] += candiesCount[i-1];
        }
        int day, type, cap;
        long long max; int min;
        for(int i =0; i<m; i++){
            day = queries[i][1];
            type = queries[i][0];
            cap = queries[i][2];
            min = day;
            if(min>candiesCount[type]) ans[i] = false;
            if(type!=0){
                max = cap*day;
                if(max<candiesCount[type-1]){
                    ans[i] = false;
                }
            }
        }
        return ans;
    }
};