#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<pair<int,int>>> &al, vector<int> & dist, vector<int> &dp, int i){
        if(i==1){
            return 1;
        }
        if(dp[i]==-1){
            dp[i] = 0;
            for(auto it : al[i]){
                int j = it.first; int w = it.second;
                if(dist[i]<dist[j]){
                    dp[i] = (dp[i] + dfs(al,dist, dp, j)) % (int)(1e9 + 7);
                }
            }
        }
        return dp[i];
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> al(n+1);
        vector<int> dist(n+1), dp(n+1,-1);

        for(auto &e: edges){
            al[e[0]].push_back({e[1],e[2]});
            al[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        pq.push({0,n});
        while(!pq.empty()){
            auto i = pq.top().second; pq.pop();
            
            for(auto it : al[i]){
                int j = it.first; int w = it.second;
                if(j!=n &&( dist[j] > dist[i] + w || dist[j]==0)){
                    dist[j] = dist[i] + w;
                    pq.push({-dist[j], j});
                }
            }
        }
        return dfs(al,dist, dp, n);      
    }
};
