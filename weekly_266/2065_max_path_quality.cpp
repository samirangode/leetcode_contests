#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void maxPathQualityHelper(int& maxVal,int node, int maxT, int val, vector<int> &vis, vector<pair<int,int>> adj[], vector<int>&values){
        if(maxT<0) return;
        
        if(vis[node]==0){
            // vis[node] =1;
            val += values[node];
            
        }
        if(node==0){
            maxVal = max(maxVal, val);
        }
        vis[node]++;
        for(auto it: adj[node]){
            int child = it.first;
            int tm = it.second;
            maxPathQualityHelper(maxVal, child, maxT-tm, val, vis, adj, values);

        }
        vis[node]--;
    }


public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<pair<int,int>> adj[n];
        int u = 0;
        int v = 0;
        int time = 0;
        for(auto it:edges){
         u = it[0];
         v = it[1];
         time = it[2];
        //  pair<int,int> a = {v,time};
         adj[u].push_back({v,time});
         adj[v].push_back({u,time});
        }
        int maxVal = 0;
        vector<int> vis(n,0);
        maxPathQualityHelper(maxVal,0,maxTime,0,vis,adj,values);

        return maxVal;        
    }
};