#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int source, vector<int>& temp, vector<vector<int>> &ans, vector<vector<int>>& graph){
        if(source==(graph.size()-1)){
            ans.push_back(temp);
            return;
        } 
        for(int v : graph[source]){
            temp.push_back(v);
            dfs(v,temp,ans,graph);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0,temp,ans,graph);
        return ans;
    }
};
