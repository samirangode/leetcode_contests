#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i< m; i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,m,n);
            }
            if(board[i][n-1]=='O'){
                dfs(board,i,n-1,m,n);
            }
        }
        for(int j = 0; j< n; j++){
            if(board[0][j]=='O'){
                dfs(board,0,j,m,n);
            }
            if(board[m-1][j]=='O'){
                dfs(board,m-1,j,m,n);
            }
        }
        for(int i =0 ; i<m ;i++){
            for(int j = 0; j< n; j++){
                if(board[i][j]=='P'){
                    board[i][j] = 'O';
                    continue;
                }
                board[i][j] = 'X';
            }
        }
        
    }
    void dfs(vector<vector<char>> &board, int i , int j, int m, int n){
        board[i][j] = 'P';
        if(i>0&&board[i-1][j]!='P'&&board[i-1][j]=='O'){
            dfs(board,i-1,j,m,n);
        }
        if(i<m-1&&board[i][j]!='P'&&board[i+1][j]=='O'){
            dfs(board,i+1,j,m,n);
        }
        if(j>0&&board[i][j-1]!='P'&&board[i][j-1]=='O'){
            dfs(board,i,j-1,m,n);
        }
        if(j<m-1&&board[i][j+1]!='P'&&board[i][j-1]=='O'){
            dfs(board,i,j+1,m,n);
        }

    }
};
