
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int>> q; int ans =0;
        int xdiff[4] = {0,0,1,-1};
        int ydiff[4] = {1,-1,0,0};
        for(int i =0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    q.push({i,j});
                }
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop(); grid[x][y] = '0';
                    for(int k = 0; k< 4; k++){
                        int x1 = x + xdiff[k];
                        int y1 = y + ydiff[k];
                        if(x1>=0&&x1<rows&&y1>=0&&y1<cols&&grid[x1][y1]=='1'){
                            q.push({x1,y1});
                            grid[x1][y1] = '0';
                        }
                    }

                }
            }
        }
        return ans;
    }

};