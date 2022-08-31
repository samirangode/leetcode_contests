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


// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         stack<TreeNode*> s;
//         int height = 0, max_h = INT_MIN;
//         int l_height = 0;
//         TreeNode* curr = root;
//         bool left = false;
//         while(curr!=NULL || !s.empty()){
//             while(curr!=NULL){
//                 s.push(curr); 
//                 if(!left) height++;
//                 left = false;
//                 if(height>max_h){
//                     ans.push_back(curr->val);
//                 }
//                 max_h = max(max_h, height);
//                 curr = curr->right;
//             }
//             curr = s.top();
//             s.pop(); height--;
//             curr = curr->left;
//             left = true;
//             if(curr->left!=nullptr) height++;
//         }
//     }
// };
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recursion(root, ans, 0);
        return ans;
    }
    void recursion(TreeNode* root, vector<int> &ans, int level){
        if(root == nullptr) return;
        if(level>ans.size()) ans.push_back(root->val);
        recursion(root->right, ans, level+1);
        recursion(root->left, ans, level+1);
        return;
    }
};