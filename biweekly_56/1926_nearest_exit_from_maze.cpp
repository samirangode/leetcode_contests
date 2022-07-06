#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row[4] = {1, 0, -1, 0};
        int col[4] = {0, -1, 0, 1};

        int ans = 0;
        queue<pair<int, int>> q;
        int m = maze.size();
        int n =  maze[0].size();

        int start_r = entrance[0];
        int start_c = entrance[1];
        // if(start_r == 0 || start_r == m-1 || start_c == 0 || start_c == n-1){
        //     return 0;
        // }
        q.push({start_r,start_c});
        int r;
        int c;
        while(!q.empty()){
            r = q.front().first;
            c = q.front().second;
            q.pop();
            if(r!=start_r && c!=start_c){
                ans++;
            }
            for(int i : row){
                for(int j : col){
                    int new_r = r+i;
                    int new_c = c+j;
                    if(new_r > 0 && new_r < m-1 && new_c > 0 && new_c < n-1 && maze[new_r][new_c]=='.'){
                        if(new_r == 0 || new_r == m-1 || new_c == 0 || new_c == n-1){
                            return ans+1;
                        }
                        if(new_r > 0 && new_r < m-1 && new_c > 0 && new_c < n-1){
                            q.push({new_r,new_c});
                            maze[new_r][new_c] = '+';
                        }
                    }
                    // if(new_r){q.push({new_r,new_c});}
                }
            }
        }
        return -1;
    }
};