#include <bits/stdc++.h>

using namespace std;

// Brute force TLE on last test case
// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int rows = heights.size();
//         int cols = heights[0].size();
//         int xdiff[4] = {0,0,1,-1};
//         int ydiff[4] = {1,-1,0,0};
//         queue<pair<int,int>> q;
//         bool atlantic, pacific;
//         vector<vector<int>> ans;
//         for(int i = 0; i<rows; i++){
//             for(int j = 0; j<cols; j++){
//                 vector<int> temp = {i,j};
//                 atlantic = false; pacific=false;
//                 unordered_set<int> visited;
//                 visited.insert(i*cols + j);
//                 q.push({i,j});
//                 if(i==0||j==0)pacific = true;
//                 if(i==rows-1||j==cols-1) atlantic = true;
//                 while(!q.empty()){
//                     int x = q.front().first;
//                     int y = q.front().second;
//                     q.pop();
//                     for(int k = 0; k<4; k++){
//                         int x1 = x + xdiff[k];
//                         int y1 = y + ydiff[k];
//                         if(x1>=0&&x1<rows&&y1>=0&&y1<cols&&heights[x1][y1]<=heights[x][y]&&visited.find(x1*cols +y1)==visited.end()){
//                             q.push({x1,y1}); visited.insert(x1*cols + y1);
//                             if(x1==0||y1==0)pacific = true;
//                             if(x1==rows-1||y1==cols-1) atlantic = true;
//                         }
//                     }
//                 }
//                 if(atlantic && pacific){
//                     ans.push_back(temp);
//                 }
//             }
//         }      
//         return ans;
//     }
// };

// Optimised
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m,vector<bool>(n));
        vector<vector<bool>> atlantic(m,vector<bool>(n));

        for(int i =0; i<m; i++){
            dfs(heights, pacific, i, 0, m, n);
            dfs(heights, atlantic, i, n-1, m, n);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, m, n);
            dfs(heights, atlantic, m - 1, j, m, n);
        }
        
        vector<vector<int>> result;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &visited, int i, int j, int m, int n){
        visited[i][j] = true;

        if(i>0&&!visited[i-1][j]&&heights[i-1][j]>=heights[i][j]){
            dfs(heights,visited,i-1,j,m,n);
        }
        if (i < m - 1 && !visited[i + 1][j] && heights[i + 1][j] >= heights[i][j]) {
            dfs(heights, visited, i + 1, j, m, n);
        }
        if (j > 0 && !visited[i][j - 1] && heights[i][j - 1] >= heights[i][j]) {
            dfs(heights, visited, i, j - 1, m, n);
        }
        if (j < n - 1 && !visited[i][j + 1] && heights[i][j + 1] >= heights[i][j]) {
            dfs(heights, visited, i, j + 1, m, n);
        }

    }
};
