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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> one; one.push(p);
        queue<TreeNode*> two; two.push(q);
        while(!one.empty() && !two.empty()){
            int m = one.size(); int n = two.size();
            if(m!=n) return false; 
            for(int i = 0; i< m; i++){
                TreeNode* oneroot = one.front(); one.pop();
                TreeNode* tworoot = two.front(); two.pop();
                int val_1_left, val_1_right, val_2_left, val_2_right;
                if(oneroot->left!=NULL){
                    one.push(oneroot->left); val_1_left = oneroot->val;
                }
                if(oneroot->right!=NULL){
                    one.push(oneroot->right); val_1_right = oneroot->val;
                }
                if(tworoot->left!=NULL){
                    one.push(tworoot->left); val_2_left = tworoot->val;
                }
                if(tworoot->right!=NULL){
                    one.push(tworoot->right); val_2_right = tworoot->val;
                }
                if(val_1_left!=val_2_left || val_1_right!=val_2_right){
                    return false;
                }
            }
        }
        return true;     
    }
};
