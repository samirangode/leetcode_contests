#include <bits/stdc++.h>

using namespace std;

struct TrieNode{
    bool flag = false;
    unordered_map<char,TrieNode*> children;
};

class Solution {
public:
    int board_rows, board_col;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode(); board_rows = board.size(); board_col = board[0].size();
        for(string word : words){
            TrieNode* temp = root;
            for(char c : word){
                if(temp->children.find(c)==temp->children.end()){
                    temp->children[c] = new TrieNode();
                }
                temp = temp->children[c];
            }
            temp->flag = true;
        }
        unordered_set<string> ans;
        for(int row = 0; row<board_rows; row++){
            for(int col = 0; col < board_col; col++){
                string temp_ans = "";
                if(root->children.find(board[row][col])!= root->children.end())
                    dfs(root->children[board[row][col]],board,ans,row,col,-1,-1,temp_ans+board[row][col]);
            }
        }
        vector<string> final_ans;
        final_ans.insert(final_ans.end(), ans.begin(), ans.end());

        return final_ans;
        
    }
    void dfs(TrieNode* new_temp, vector<vector<char>> &board, unordered_set<string> &ans, int row, int col, int prev_row, int prev_col, string temp_ans){
        // cout<<temp_ans<<endl;
        TrieNode* temp = new_temp;
        // if(temp->children.find(board[row][col])==temp->children.end()) return;
        if(temp->flag) ans.insert(temp_ans);
        
        if(check_row_col(row+1,col,prev_row,prev_col) && temp->children.find(board[row+1][col])!=temp->children.end()){
            dfs(temp->children[board[row+1][col]],board,ans,row+1,col,row,col, temp_ans + board[row+1][col]);
        }
        // temp= new_temp;
        if(check_row_col(row-1,col,prev_row,prev_col) && temp->children.find(board[row-1][col])!=temp->children.end()){
            dfs(temp->children[board[row-1][col]],board,ans,row-1,col,row,col, temp_ans + board[row-1][col]);
        }
        // temp= new_temp;
        // for(auto it : temp->children){
        //     cout<<it.first<<endl;
        // }
        if(check_row_col(row,col+1,prev_row,prev_col) && temp->children.find(board[row][col+1])!=temp->children.end()){
            dfs(temp->children[board[row][col+1]],board,ans,row,col+1,row,col, temp_ans + board[row][col+1]);
        }
        // temp = new_temp;
        if(check_row_col(row,col-1,prev_row,prev_col) && temp->children.find(board[row][col-1])!=temp->children.end()){
            dfs(temp->children[board[row][col-1]],board,ans,row,col-1,row,col, temp_ans + board[row][col-1]);
        }
        
    }
    bool check_row_col(int row, int col, int prev_row, int prev_col){
        bool one = !((row==prev_row) && (col==prev_col));
        bool two =  (row<board_rows) && (col<board_col) && (row>=0) && (col>=0);
        return one&&two;
    }
};
