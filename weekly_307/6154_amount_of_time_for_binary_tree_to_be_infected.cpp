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
    int max_dist = 0;
    int amountOfTime(TreeNode* root, int start) {
        int val = dfs(root, start);
        return max_dist;
    }
    int dfs(TreeNode* root, int start){
        if(root == NULL) return 0;
        if(root->val){
            // max distance from childrem
            int left = dfs(root->left, start);
            int right = dfs(root->right, start);
            max_dist = max(max_dist, max(left,right));
            return 1;
            
        }
        int left = dfs(root->left, start);
        int right = dfs(root->right, start);
        max_dist = max(max(left,right)+1, max_dist);
        return max(left,right)+1;
    }
};
