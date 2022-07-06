#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        int X[4] = {1,-1,0,0};
        int Y[4] = {0,0,1,-1}; 
        queue<pair<int,int>> q;
        vector<vector<int>> height(n, vector<int>(m,0));
        for(int i = 0; i< n; i++){
            for(int j = 0; j<m; j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int q_size = q.size(); int dist = 0;
            while(q_size>0){
                dist++;
                int x = q.front().first;
                int y = q.front().second;
                q.pop(); q_size--;
                int x1, y1;
                for(int k = 0; k<4; k++){
                    x1 = x + X[k];
                    y1 = y + Y[k];
                    if(x1>=0 && x1<n && y1>=0 && y1< m && 
                    isWater[x1][y1]==0){
                        q.push({x1,y1}); isWater[x1][y1] = 2;
                        height[x1][y1] = dist;
                    }
                }

            }
        }

        return height;
    }
};