#include <bits/stdc++.h>

using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_val = INT_MIN;
        // int left = 0;
        // int right = 0;
        int val = dfs(root,max_val);
        max_val = max(max_val,val);
        return max_val;
    }
    int dfs(TreeNode* root, int &max_val){
        if(root == NULL) return 0;
        int left = dfs(root->left, max_val);
        int right = dfs(root->right,max_val);
        int max_child = max(left, right);
        int full_path = left+right+root->val;
        int max_return_val = max(max(max_child+root->val,full_path),root->val);
        max_val = max(max(max(max_child,full_path),root->val),max_val);
        // if(max_child>full_path){
        //     return max_child + root->val; 
        // }
        // return full_path;
        return max_return_val;
    }
};
