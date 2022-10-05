#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<unordered_set<char>> rows(n);
        vector<unordered_set<char>> cols(n);
        vector<vector<unordered_set<int>>> sub_matrix(3,vector<unordered_set<int>>(3));
        for(int i =0; i<n;i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(rows[i].find(board[i][j])!=rows[i].end()){
                    return false;
                }
                if(cols[j].find(board[i][j])!=cols[j].end()){
                    return false;
                }
                if(sub_matrix[i/3][j/3].find(board[i][j])!=sub_matrix[i/3][j/3].end()){
                    return false;
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                sub_matrix[i/3][j/3].insert(board[i][j]);
            }
        }
        return true;      
    }
};
