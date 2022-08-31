#include <bits/stdc++.h>

using namespace std;


//  Definition for a binary tree node.
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
    int max_depth = 0;
    int maxDepth(TreeNode* root) {
        int depth = 1;
        dfs(root,depth);
        return max_depth;

    }
    void dfs(TreeNode* root, int &depth){
        if(root==NULL) return;
        max_depth = max(depth, max_depth);
        depth+=1;
        dfs(root->left,depth);
        dfs(root->right,depth);
        depth-=1;
        return;
    }
};
