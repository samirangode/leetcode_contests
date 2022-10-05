#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        int xdiff[4] = {0,0,-1,1};
        int ydiff[4] = {1,-1,0,0};
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i = 0; i< m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int minutes = 0;
        while(!q.empty()){
            minutes++;
            int num = q.size();
            for(int i = 0; i < num; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k = 0; k< 4; k++){
                    int x1= x + xdiff[k];
                    int y1 = y + ydiff[k];
                    if(x1>=0&&y1>=0&&x1<m&&y1<n&&grid[x1][y1]==1){
                        q.push({x1,y1});
                        grid[x1][y1] = 2; fresh--;
                    }
                }
            }
        }
        if(fresh){
            return -1;
        }
        return minutes;
    }
};
