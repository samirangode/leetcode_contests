#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        int xdiff[4] = {0,0,-1,1};
        int ydiff[4] = {1,-1, 0,0};
        queue<pair<int,int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int dist = 0;
        while(!q.empty()){
            dist++;
            int num = q.size();
            for(int i = 0; i< num; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0; k<4; k++){
                int x1 = x + xdiff[k];
                int y1 = y + ydiff[k];
                if(x1>=0&&x1<m&&y1>=0&&y1<n&&rooms[x1][y1]==2147483647){
                        rooms[x1][y1] = dist;
                        q.push({x1,y1});
                }
                }
            }
        }
    }
};
