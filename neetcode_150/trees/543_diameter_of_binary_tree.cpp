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
    int diameterOfBinaryTree(TreeNode* root) {
        int max_sum = 0;
        dfs(root, max_sum);
        return max_sum;
    }
    // returns the sum of l + r subtrees
    int dfs(TreeNode* root, int &max_sum){
        if(root==NULL) return 0;
        int l = dfs(root->left, max_sum);
        int r = dfs(root->right, max_sum);
        max_sum = max(max_sum, l+r+1);
        return l + r + 1;
    }
};
