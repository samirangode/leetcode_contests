#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>>  um;
        int n = logs.size();
        for(int i =0; i<n;i++){
            // if(um.find(logs[i][0]) != um.end()){
            //     um[logs[i][0]] = min(logs[i][1],um[logs[i][0]]);
            // }else{
            //     um[logs[i][0]] = logs[i][1];
            // }
            um[logs[i][0]].insert(logs[i][1]);
        }
        vector<int> ans(k);
        int temp_uam = 0;
        for(auto it : um){
            temp_uam = it.second.size();
            ans[temp_uam-1]++;
        }
        return ans; 
    }
};

