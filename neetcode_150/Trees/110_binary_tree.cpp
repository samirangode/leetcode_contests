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
 
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL) return true;
//         queue<TreeNode*> q;
//         q.push(root);
//         int s, min_level = INT_MAX, level = 0;
//         while(!q.empty()){
//             s = q.size();
//             level++;
//             for(int i = 0; i< s; i++){
//                 TreeNode* d = q.front();
//                 q.pop();
//                 if(d->left) q.push(d->left);
//                 if(d->right) q.push(d->right);

//                 if(!(d->left) && !(d->right)) min_level = min(level, min_level);
//             }
//         }  
//         return (level - min_level) <=1 ;
//     }
// };
// DFS solution
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        // stack<TreeNode*> s;
        // s.push(root);
        // Need to think about the iterative DFS variant to this solution
        int height = -1;
        return dfs(root, height);
    }
    bool dfs(TreeNode* root, int &height){
        if(root==NULL){
            height = -1;
            return true;
        }
        int left = 0; 
        int right = 0;
        bool cond_left = dfs(root->left, left);
        bool cond_right = dfs(root->right, right);
        height = 1 + max(left, right);
        return cond_left && cond_right && (abs(left - right)<=1);
    }
};