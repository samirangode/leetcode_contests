#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool dfs(int source, int& destination, vector<vector<int>>& adjList, vector<bool>& visited){
        if(source==destination) return true;
        for(int i : adjList[source]){
            if(!visited[i]){
                visited[i] =true;
                dfs(i, destination, adjList, visited);
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,false);
        return dfs(source, destination,adjList, visited);
    }
    
};