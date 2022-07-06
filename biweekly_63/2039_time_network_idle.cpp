#include <bits/stdc++.h>

using namespace std;

void add_edge(int A, vector<vector<int>> edges, vector<int> adjList[]){
    int n = edges.size();
    for(int i =0 ; i< n; i++){
        adjList[edges[i][0]-1].push_back(edges[i][1]-1);
    }

}
    




class Solution {
public:
    
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int A = patience.size();
        vector<int> distance;
        distance.resize(A,0);

        vector<int> adjList[A];
        add_edge(A, edges, adjList);
        queue<int> q;
        vector<bool> visited;
        visited.resize(A+1,false);
        q.push(0);
        visited[0] = true;
        int i = 0 ;
        while(!q.empty()){
            int s = q.front();
            q.pop();
            i++;
            for(int u : adjList[s]){
                if(!visited[u]){
                    q.push(u);
                    visited[u] = true;
                    distance[u] = i;
                }
            }

        }
        int maxi = 0;
        int m = distance.size();
        int tempt = 0;
        int a = 0;
        for(int i = 1; i < m; i++){
            if(patience[i]<2*distance[i]){
                if(2*distance[i]%patience[i] == 0){
                    a = (2*distance[i])/patience[i] - i;
                    maxi = max(maxi, a*patience[i] + 2*distance[i]);
                }
                else{
                    a =  (2*distance[i])/patience[i];
                    maxi = max(maxi, a*patience[i] + 2*distance[i]);

                }
            }
            else{
                maxi = max(maxi, 2*distance[i]);
            }
        }
        return maxi;
    }
};